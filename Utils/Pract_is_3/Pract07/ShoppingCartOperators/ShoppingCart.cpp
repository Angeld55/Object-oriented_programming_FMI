#include "ShoppingCart.h"

void ShoppingCart::resize(unsigned newCapacity)
{
	Product* newProducts = new Product[newCapacity];

	for (size_t i = 0; i < count; i++)
	{
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

ShoppingCart::ShoppingCart()
{
	products = new Product[capacity];
}

ShoppingCart& ShoppingCart::operator+=(const Product& product)
{
	if (count >= capacity)
	{
		resize(capacity * 2);
	}

	products[count++] = product;
}

ShoppingCart& ShoppingCart::operator-=(const Product& product)
{
	// TODO: insert return statement here
}

const Product& ShoppingCart::operator[](size_t index) const
{
	return products[index];
}

Product& ShoppingCart::operator[](size_t index)
{
	return products[index];
}
