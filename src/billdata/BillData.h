#ifndef BILLDATA_H
#define BILLDATA_H

#include "../cart/CartItem.h"
#include <vector>

class BillData {
public:
	const double subTotal;
	const double totalDiscount;
	const double taxAmount;
	const double finalAmount;
	const std::vector<CartItem>& items;

	BillData(
		double subTotal, 
		double totalDiscount, 
		double taxAmount, 
		double finalAmount, 
		const std::vector<CartItem>& items
	);
};

#endif