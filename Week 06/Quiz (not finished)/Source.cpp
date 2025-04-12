#include <iostream>
#include "Quiz.h"
int main()
{
	Quiz q(5);

	Question question("Capital of germany? ", "Berlin", "London", "New York", "Hamburg", 1);

	q.addQuestion(question);
}
