#include "Product.h"
#include <stdexcept>

Product::Product(int id, const std::string& name, double price) {

	if (price < 0)	throw std::invalid_argument("Product price must be non-negative");
	this->id = id;
	this->name = name;
	this->price = price;
}

int Product::getId() const {
	return this->id;
}

std::string Product::getName() const {
	return this->name;
}

double Product::getPrice() const {
	return this->price;
}