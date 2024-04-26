//#include <iostream>
//
//class Example {
//	int a;
//
//public:
//	int getA() const{
//		return a;
//	}
//
//	void setA(int a) {
//		this->a = a;
//	}
//};
//
//int main()
//{
//    //allocates memory for 3 Example objects
//    Example* ptr = (Example*) new char[3 * sizeof(Example)];
//  
//    //allocates ex1 at the address of ptr[0]
//    Example* ex1 = new (&ptr[0]) Example;
//  
//    //allocates ex2 at the address of ptr[1]
//    Example* ex2 = new (&ptr[1]) Example;		
//  
//    ex1->setA(3);
//    ex2->setA(42);
//  
//    std::cout << ex1->getA() << std::endl;
//    std::cout << ex2->getA() << std::endl;
//  
//    //we should always call the destructors explicitly!!!
//    ex1->~Example();
//    ex2->~Example();
//  
//    delete[]((char*)ptr);
//}
