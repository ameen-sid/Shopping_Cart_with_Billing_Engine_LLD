#ifndef CARTITEM_H
#define CARTITEM_H

#include "../product/Product.h"

class CartItem {
private:
	const Product* product;	// CartItem does not own Product
	int quantity;

public:
	CartItem(const Product* product, int quantity);

	const Product* getProduct() const;
	int getQuantity() const;

	void setQuantity(int quantity);
};

#endif