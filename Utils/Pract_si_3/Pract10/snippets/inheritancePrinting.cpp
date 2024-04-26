//#include <iostream>
//
//class User {
//public:
//	User() {
//		std::cout << "User()" << std::endl;
//	}
//	User(const User& other) {
//		std::cout << "CC of User()" << std::endl;
//	}
//	User(User&& other) noexcept {
//		std::cout << "MC of User()" << std::endl;
//	}
//	User& operator=(const User& other) {
//		std::cout << "OP= of User()" << std::endl;
//		return *this;
//	}
//	User&  operator=(User&& other) noexcept {
//		std::cout << "MOP= of User()" << std::endl;
//		return *this;
//	}
//	~User() {
//		std::cout << "~User()" << std::endl;
//	}
//};
//
//class PremiumUser : public User {
//public:
//	PremiumUser() {
//		std::cout << "PremiumUser()" << std::endl;
//	}
//	PremiumUser(const PremiumUser& other) : User(other) {
//		std::cout << "CC of PremiumUser()" << std::endl;
//	}
//	PremiumUser(PremiumUser&& other) noexcept : User(std::move(other)) {
//		std::cout << "MC of PremiumUser()" << std::endl;
//	}
//	PremiumUser& operator=(const PremiumUser& other) {
//		User::operator=(other);
//		std::cout << "OP= of PremiumUser()" << std::endl;
//		return *this;
//	}
//	PremiumUser& operator=(PremiumUser&& other) noexcept {
//		User::operator=(std::move(other));
//		std::cout << "MOP= of PremiumUser()" << std::endl;
//		return *this;
//	}
//	~PremiumUser() {
//		std::cout << "~PremiumUser()" << std::endl;
//	}
//};
//
//int main() 
//{
//  PremiumUser p1;
//  PremiumUser p2 = p1;
//  PremiumUser p3;
//  p3 = p2;
//  p3 = std::move(p1);
//}
