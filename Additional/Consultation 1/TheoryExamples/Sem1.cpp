#include <iostream>

struct Test {
	int a = 0;
};

void memory() {
	int a = 5; // int in the stack
	int* b = new int; // pointer in the stack and int in the heap
	int arr[5]; // pointer and 5 * ints in the stack
	int* dynamicArr = new int[5]; // pointer in the stack and 5 * ints in the heap

	delete b;
	delete[] dynamicArr;
}

void passByCopy(Test t) {
	t.a++;
}

void passByRef(Test& t) {
	t.a++;
}

void passByConstRef(const Test& t) {
	// error t.a++;
}

// passByPointer(&t)
void passByPointer(Test* t) {
	t->a++;
}

void structInit() {
	struct Box {
		double height, width, length;
	};
	Box b; // default values to height and width and length
	Box b2 = { 3, 4, 3.4 }; // height = 3, width = 3, length = 3.4;
	Box b3;
	b3.height = 13;
	b3.width = 14;
	b3.length = 20;
}

void padding() {
	struct A
	{
		bool b;     // 1 byte
		int c;	    // 4 bytes
	} a;
	std::cout << sizeof(a) << std::endl; // 8
}


namespace Constants {
	const short MAX_NAME_SIZE = 20;
}


void testNamespace() {
	Constants::MAX_NAME_SIZE;
	using namespace Constants;
	MAX_NAME_SIZE;
}

void unscopedEnums() {
	enum Fruit {
		Apple = 0
	};

	enum Vegetable {
		Pumpkin = 0
	};

	Fruit f = Apple;
	Vegetable v = Pumpkin;

	if (f == v) {
		std::cout << "hello";
	}

	if (f == Pumpkin) {
		std::cout << "hello2";
	}
}

void scopedEnums() {
	enum class Fruit {
		Apple = 0
	};

	enum class Vegetable {
		Pumpkin = 0
	};

	Fruit f = Fruit::Apple;
	Vegetable v = Vegetable::Pumpkin;

	//if (f == v) { // can not compare fruit to vegetable
	//	std::cout << "hello";
	//}
}