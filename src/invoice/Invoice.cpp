#include "Invoice.h"
#include <iostream>
#include <iomanip>
#include <sstream>

std::string Invoice::generateInvoiceText(const BillData& billdata) const {

	std::ostringstream oss;
	oss << "---- INVOICE ----\n\n";

	// items
	for (const CartItem& item : billdata.items) {

		const Product* product = item.getProduct();
		oss << std::left << std::setw(12) << product->getName() 
			<< "x" << item.getQuantity() 
			<< "   Rs. " << product->getPrice() * item.getQuantity()
			<< "\n";
	}

	oss << "\n-------------------\n\n";
	oss << "Subtotal: Rs. " << billdata.subTotal << "\n";
	oss << "Discount: Rs. " << billdata.totalDiscount << "\n";
	oss << "Tax: Rs. " << billdata.taxAmount << "\n";
	oss << "\n-------------------\n\n";
	oss << "Total Payable: Rs. " << billdata.finalAmount << "\n";

	return oss.str();
}

void Invoice::printToConsole(const BillData& billdata) const {
	std::cout << this->generateInvoiceText(billdata);
}