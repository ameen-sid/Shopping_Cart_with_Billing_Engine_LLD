#include "BillData.h"

BillData::BillData(
	double subTotal, 
	double totalDiscount, 
	double taxAmount, 
	double finalAmount, 
	const std::vector<CartItem>& items
)
	: 	subTotal(subTotal), 
		totalDiscount(totalDiscount),
		taxAmount(taxAmount),
		finalAmount(finalAmount),
		items(items) 
{}