#pragma once
#include "Product.h"

class ShoppingCart {
private:
	Product* products = nullptr;
	unsigned count = 0;
	unsigned capacity = 16;

	void free();
	void copyFrom(const ShoppingCart& other); 
	void resize(unsigned newCapacity);

public:
	ShoppingCart();
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);
	~ShoppingCart();

	ShoppingCart& operator+=(const Product& product);
	ShoppingCart& operator-=(const Product& product);

	const Product& operator[](size_t index) const;
	Product& operator[](size_t index);
};