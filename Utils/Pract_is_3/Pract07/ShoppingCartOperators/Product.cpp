#include "Product.h"

std::ostream& operator<<(std::ostream& os, const Product& product)
{
    os << product.getName() << ' ' << product.getPrice() << ' ' << product.getQuantity();
}

std::istream& operator>>(std::istream& is, Product& product)
{
    // name , price, quantity;

    char buff[1024];
    is >> buff; // 2.4 5 kiselo mlqko // kiseloMlqko
    product.setName(buff);

    double price;
    is >> price;
    product.setPrice(price);

    unsigned quantity;
    is >> quantity;
    product.setQuantity(quantity);
}

void Product::copyFrom(const Product& other)
{
    unsigned sizeName = strlen(other.name);
    name = new char[sizeName + 1];
    strcpy(name, other.name);
    price = other.price;
    quantity = other.quantity;
}

void Product::free()
{
    delete[] name;
    name = nullptr;
    price = 0;
    quantity = 0;
}

Product::Product(const char* name, double price, unsigned quantity)
{
    setName(name);
    setPrice(price);
    setQuantity(quantity);
}

Product::Product(const Product& other)
{
    copyFrom(other);
}

Product& Product::operator=(const Product& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Product::~Product()
{
    free();
}

Product& Product::operator++()
{
    ++quantity;
    return *this;
}

Product Product::operator++(int) // a++
{
    Product res(*this);
    ++(*this);
    return res;
}

void Product::setName(const char* name) // product // product.setName("Qbulka")
{
    if (!name || name == this->name)
    {
        return;
    }

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Product::setPrice(double price)
{
    if (price < 0)
    {
        price = 1;
    }
    this->price = price;
}

void Product::setQuantity(unsigned quantity)
{
    if (quantity == 0)
    {
        quantity = 1;
    }
    this->quantity = quantity;
}

const char* Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

unsigned Product::getQuantity() const
{
    return quantity;
}
