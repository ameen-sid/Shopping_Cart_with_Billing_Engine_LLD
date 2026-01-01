#ifndef THRESHOLDDISCOUNT_H
#define THRESHOLDDISCOUNT_H

#include "Discount.h"

class ThresholdDiscount : public Discount {
private:
	double thresholdAmount;
	double discountAmount;

public:
	explicit ThresholdDiscount(double thresholdAmount, double discountAmount);

	double calculateDiscount(double subTotal) const override;
};

#endif