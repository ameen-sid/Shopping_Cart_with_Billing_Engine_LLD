#ifndef CART_H
#define CART_H

#include "../product/Product.h"
#include "CartItem.h"
#include <vector>

class Cart {
private:
	std::vector<CartItem> cartItems;

	bool isPresent(const Product* product) const;

public:
	void addProduct(const Product* product, int quantity);
	void removeProduct(const Product* product);
	void updateQuantity(const Product* product, int quantity);

	double calculateSubTotal() const;
	const std::vector<CartItem>& getItems() const;
};

#endif