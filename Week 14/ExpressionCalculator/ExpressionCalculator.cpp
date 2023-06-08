#include "ExpressionCalculator.h"
#include <stdexcept>

namespace {
	const char AND = '^';
	const char OR = 'v';
	const char IMPL = '>'; //=>
	const char IFF = '='; // <=>
	const char XOR = '+';
	const char NEG = '!';

	bool isOperator(char ch) {
		return ch == AND || ch == OR || ch == IFF || ch == IMPL || ch == XOR || ch == NEG;
	}
}

/// BooleanInterpretation
bool ExpressionCalculator::BooleanInterpretation::isValidCharacter(char ch) {
	return 'A' <= ch && ch <= 'Z';
}

ExpressionCalculator::BooleanInterpretation ExpressionCalculator::BooleanInterpretation::createFromNumber(size_t number, const bool variables[CHARACTERS_COUNT]) {
	BooleanInterpretation result;

	for (size_t i = 0; i < CHARACTERS_COUNT; i++) {
		if (variables[i]) {
			if (number & 1) { // (number % 2) != 0
				result.setValue('A' + i, true);
			}

			number >>= 1; // number /= 2
		}
	}

	return result;
}

bool ExpressionCalculator::BooleanInterpretation::getValue(char ch) const {
	if (!BooleanInterpretation::isValidCharacter(ch)) {
		throw std::exception("Invalid character");
	}

	return variables[ch - 'A'];
}

void ExpressionCalculator::BooleanInterpretation::setValue(char ch, bool value) {
	if (!BooleanInterpretation::isValidCharacter(ch)) {
		throw std::exception("Invalid character");
	}

	variables[ch - 'A'] = value;
}

///

///  Variable
ExpressionCalculator::Variable::Variable(char ch) : ch(ch) {
	variables[ch - 'A'] = true;
	variablesCount = 1;
}

bool ExpressionCalculator::Variable::evaluate(const BooleanInterpretation& interpretation) const {
	return interpretation.getValue(ch);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::Variable::clone() const {
	return new Variable(*this);
}

///

/// Unary Expression

ExpressionCalculator::UnaryExpression::UnaryExpression(char operand, BooleanExpression* expression)
	: operand(operand), expression(expression)
{
	for (size_t i = 0; i < CHARACTERS_COUNT; i++) {
		variables[i] = expression->variables[i];
	}

	variablesCount = expression->variablesCount;
}

bool ExpressionCalculator::UnaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	if (operand != NEG) {
		return false;
	}

	return !expression->evaluate(interpretation);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::UnaryExpression::clone() const {
	return new UnaryExpression(operand, expression->clone());
}

ExpressionCalculator::UnaryExpression::~UnaryExpression() {
	delete expression;
}
///

/// Binary Expression

ExpressionCalculator::BinaryExpression::BinaryExpression(char operand, BooleanExpression* left, BooleanExpression* right)
	: operand(operand), left(left), right(right)
{
	for (size_t i = 0; i < CHARACTERS_COUNT; i++) {
		variables[i] = left->variables[i] || right->variables[i];
		if (variables[i]) {
			variablesCount++;
		}
	}
}

bool ExpressionCalculator::BinaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	switch (operand) {
	case OR: return  left->evaluate(interpretation) || right->evaluate(interpretation);
	case AND: return left->evaluate(interpretation) && right->evaluate(interpretation);
	case IMPL: return !left->evaluate(interpretation) || right->evaluate(interpretation);
	case IFF: return left->evaluate(interpretation) == right->evaluate(interpretation);
	case XOR: return left->evaluate(interpretation) != right->evaluate(interpretation);
	default: return false; break;
	}
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::BinaryExpression::clone() const {
	return new BinaryExpression(operand, left->clone(), right->clone());
}

ExpressionCalculator::BinaryExpression::~BinaryExpression() {
	delete left;
	delete right;
}

///


/// ExpressionCalculator

bool ExpressionCalculator::checkAllVariations(const BooleanExpression* expression, bool expectedValue) {
	size_t variationsCount = 1 << expression->variablesCount;

	for (size_t i = 0; i < variationsCount; i++) {
		if (expression->evaluate(BooleanInterpretation::createFromNumber(i, expression->variables))
			!= expectedValue) {
			return false;
		}
	}

	return true;
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::ExpressionCalculator::parseExpression(const StringView& str) {
	if (str.length() == 0) {
		return nullptr;
	}

	if (str.length() == 1) {
		return new Variable(str[0]);
	}

	StringView strWithoutBrackets = str.substr(1, str.length() - 2);
	size_t length = strWithoutBrackets.length();
	size_t bracketsCounter = 0;
	for (size_t i = 0; i < length; i++) {
		if (strWithoutBrackets[i] == '(') {
			bracketsCounter++;
		}
		else if (strWithoutBrackets[i] == ')') {
			bracketsCounter--;
		}
		else if (isOperator(strWithoutBrackets[i]) && bracketsCounter == 0) {
			if (strWithoutBrackets[i] == NEG) {
				return new UnaryExpression(
					NEG,
					parseExpression(
						strWithoutBrackets.substr(i + 1, length - i - 1)
					)
				);
			}
			else {
				return new BinaryExpression(
					strWithoutBrackets[i],
					parseExpression(strWithoutBrackets.substr(0, i)),
					parseExpression(strWithoutBrackets.substr(i + 1, length - i - 1))
				);
			}
		}
	}

	return nullptr;
}

ExpressionCalculator::ExpressionCalculator(const MyString& str) : expression(parseExpression(str)) { }

ExpressionCalculator::ExpressionCalculator(const ExpressionCalculator& other) {
	copyFrom(other);
}

ExpressionCalculator::ExpressionCalculator(ExpressionCalculator&& other) noexcept {
	move(std::move(other));
}

ExpressionCalculator& ExpressionCalculator::operator=(const ExpressionCalculator& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

ExpressionCalculator& ExpressionCalculator::operator=(ExpressionCalculator&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

ExpressionCalculator::~ExpressionCalculator() {
	free();
}

bool ExpressionCalculator::isTautology() const {
	return checkAllVariations(expression, true);
}

bool ExpressionCalculator::isContradiction() const {
	return checkAllVariations(expression, false);
}

void ExpressionCalculator::copyFrom(const ExpressionCalculator& other) {
	expression = other.expression->clone();
}

void ExpressionCalculator::move(ExpressionCalculator&& other) {
	expression = other.expression;
	other.expression = nullptr;
}

void ExpressionCalculator::free() {
	delete expression;
}

///
