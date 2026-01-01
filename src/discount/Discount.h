#ifndef DISCOUNT_H
#define DISCOUNT_H

class Discount {
public:
	virtual double calculateDiscount(double subTotal) const = 0;
	virtual ~Discount() = default;
};

#endif