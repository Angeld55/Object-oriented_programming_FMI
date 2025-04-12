#pragma once
#include "Question.h"
class Quiz
{
public:
	Quiz(size_t maxQuestions);
	Quiz(const Quiz& other);
	Quiz& operator=(const Quiz& other);
	~Quiz();
	void addQuestion(const Question& q);

	size_t getSize() const;
	size_t isFull() const;
private:

	void copyDynamic(const Quiz& other);
	void freeDynamic();

	Question* questions;
	size_t size;
	size_t capacity;
};

