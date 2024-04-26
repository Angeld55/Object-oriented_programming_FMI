//#include <iostream>
//
//class A {
//public:
//	int x;
//};
//class B : public A {
//public:
//	int y;
//};
//
//void acceptCopyOfA(A obj) {}
//void acceptCopyOfB(B obj) {}
//void acceptRefOfA(A& ref) {}
//void acceptRefOfB(B& ref) {}
//void acceptPtrOfA(A* ptr) {}
//void acceptPtrOfB(B* ptr) {}
//void acceptRvalueRefOfA(A&& ptr) {}
//void acceptRvalueRefOfB(B&& ptr) {}
//
//int main() 
//{
//  A a;
//  B b;
//  acceptCopyOfA(a);
//  acceptCopyOfA(b); //only if b has inherited a as public
//  acceptCopyOfB(a); //not allowed
//  acceptCopyOfB(b);
//  acceptRefOfA(a);
//  acceptRefOfA(b); //only if b has inherited a as public
//  acceptRefOfB(a); //not allowed
//  acceptRefOfB(b);
//  acceptRvalueRefOfA(std::move(a));
//  acceptRvalueRefOfA(std::move(b)); //only if b has inherited a as public
//  acceptRvalueRefOfB(std::move(a)); //not allowed
//  acceptRvalueRefOfB(std::move(b));
//  acceptPtrOfA(&a);
//  acceptPtrOfA(&b); //only if b has inherited a as public
//  acceptPtrOfB(&a); //not allowed
//  acceptPtrOfB(&b);
//}
