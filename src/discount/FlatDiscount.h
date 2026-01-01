#ifndef FLATDISCOUNT_H
#define FLATDISCOUNT_H

#include "Discount.h"

class FlatDiscount : public Discount {
private:
	double flatAmount;

public:
	explicit FlatDiscount(double flatAmount);

	double calculateDiscount(double subTotal) const override;
};

#endif