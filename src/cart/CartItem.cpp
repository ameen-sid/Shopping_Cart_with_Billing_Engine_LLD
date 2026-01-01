#include "CartItem.h"
#include <stdexcept>

CartItem::CartItem(const Product* product, int quantity) {

	if (!product)	throw	std::invalid_argument("Product cannot be null");
	if (quantity < 0)	throw std::invalid_argument("Quantity must be non-negative");
	this->product = product;
	this->quantity = quantity;
}

const Product* CartItem::getProduct() const {
	return this->product;
}

int CartItem::getQuantity() const {
	return this->quantity;
}

void CartItem::setQuantity(int quantity) {

	if (quantity < 0)	throw std::invalid_argument("Quantity must be non-negative");
	this->quantity = quantity;
}