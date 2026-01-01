#include "Tax.h"
#include <stdexcept>

Tax::Tax(double taxRate) {

	if (taxRate < 0 || taxRate > 100)	throw std::invalid_argument("Tax rate must be between 0 and 100");
	this->taxRate = taxRate;
}

double Tax::calculateTax(double amountAfterDiscount) const {

	if (amountAfterDiscount <= 0)	return 0.0;
	return (this->taxRate / 100.0) * amountAfterDiscount;
}

void Tax::setTaxRate(double taxRate) {

	if (taxRate < 0 || taxRate > 100)	throw std::invalid_argument("Tax rate must be between 0 and 100");
	this->taxRate = taxRate;
}