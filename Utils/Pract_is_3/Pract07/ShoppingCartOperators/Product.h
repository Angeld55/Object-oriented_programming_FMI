#pragma once
#include <iostream>

class Product {
	char* name = nullptr;
	double price = 0;
	unsigned quantity = 0;

	void copyFrom(const Product& other);
	void free();

public:
	Product() = default;
	Product(const char* name, double price, unsigned quantity);
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	Product& operator++();
	Product operator++(int);

	void setName(const char* name);
	void setPrice(double price);
	void setQuantity(unsigned quantity);

	const char* getName() const;
	double getPrice() const;
	unsigned getQuantity() const;

	 
	friend std::istream& operator>>(std::istream& is, Product& product);
};

std::ostream& operator<<(std::ostream& os, const Product& product);