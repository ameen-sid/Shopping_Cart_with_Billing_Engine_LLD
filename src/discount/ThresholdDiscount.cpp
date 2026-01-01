#include "ThresholdDiscount.h"
#include <stdexcept>

ThresholdDiscount::ThresholdDiscount(double thresholdAmount, double discountAmount) {

	if (thresholdAmount < 0)	throw std::invalid_argument("Threshold amount must be non-negative");
	if (discountAmount < 0)	throw std::invalid_argument("Discount amount must be non-negative");
	this->thresholdAmount = thresholdAmount;
	this->discountAmount = discountAmount;
}

double ThresholdDiscount::calculateDiscount(double subTotal) const {

	if (subTotal >= this->thresholdAmount)	return this->discountAmount;
	return 0.0;
}