#include "FlatDiscount.h"
#include <stdexcept>

FlatDiscount::FlatDiscount(double flatAmount) {

	if (flatAmount < 0)	throw std::invalid_argument("Flat discount must be non-negative");
	this->flatAmount = flatAmount;
}

double FlatDiscount::calculateDiscount(double subTotal) const {
	return this->flatAmount;
}