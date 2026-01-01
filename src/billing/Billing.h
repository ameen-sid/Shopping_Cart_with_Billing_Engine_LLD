#ifndef BILLING_H
#define BILLING_H

#include "../cart/Cart.h"
#include "../discount/Discount.h"
#include "../tax/Tax.h"
#include "../billdata/BillData.h"
#include <vector>

class Billing {
public:
	BillData generateBill(
		const Cart& cart, 
		const std::vector<Discount*>& discounts, 
		const Tax& tax
	) const;
};

#endif