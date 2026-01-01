#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include "../product/Product.h"
#include "../cart/Cart.h"
#include "../billing/Billing.h"
#include "../invoice/Invoice.h"
#include "../storage/Storage.h"
#include "../tax/Tax.h"
#include "../discount/Discount.h"

class UserInteraction {
private:
	Cart& cart;
	Billing& billing;
	Invoice& invoice;
	Storage& storage;
	Tax& tax;
	std::vector<Discount*>& discounts;
	std::vector<Product>& products;

public:
	UserInteraction(
		Cart& cart,
		Billing& billing,
		Invoice& invoice,
		Storage& storage,
		Tax& tax,
		std::vector<Discount*>& discounts,
		std::vector<Product>& products
	);

	void start();
	void listProducts();
	void addProduct();
	void removeProduct();
	void generateBill();
};

#endif