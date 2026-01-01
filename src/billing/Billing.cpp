#include "Billing.h"
#include <algorithm>

BillData Billing::generateBill(
	const Cart& cart, 
	const std::vector<Discount*>& discounts, 
	const Tax& tax
) const {

	// 1. subtotal
	double subTotal = cart.calculateSubTotal();

	// 2. total discount
	double totalDiscount = 0;
	for (const Discount* discount : discounts)	totalDiscount += discount->calculateDiscount(subTotal);

	// 3. cap discount to subtotal
	if (totalDiscount > subTotal)	totalDiscount = subTotal;

	// 4. amount after discount
	double amountAfterDiscount = subTotal - totalDiscount;

	// 5. tax
	double taxAmount = tax.calculateTax(amountAfterDiscount);

	// 6. final amount
	double finalAmount = amountAfterDiscount + taxAmount;

	// 7. return immutable bill data
	return BillData(
		subTotal, 
		totalDiscount, 
		taxAmount, 
		finalAmount, 
		cart.getItems()
	);
}