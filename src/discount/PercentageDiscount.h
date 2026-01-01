#ifndef PERCENTAGEDISCOUNT_H
#define PERCENTAGEDISCOUNT_H

#include "Discount.h"

class PercentageDiscount : public Discount {
private:
	double percentage;

public:
	explicit PercentageDiscount(double percentage);

	double calculateDiscount(double subTotal) const override;
};

#endif