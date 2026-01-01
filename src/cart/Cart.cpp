#include "Cart.h"
#include <stdexcept>
#include <algorithm>

bool Cart::isPresent(const Product* product) const {

    for (const CartItem& item : this->cartItems) {
        if (item.getProduct()->getId() == product->getId()) return true;
    }
    return false;
}

void Cart::addProduct(const Product* product, int quantity) {

    if (quantity < 0)   throw std::invalid_argument("Quantity must be non-negative");
    for (CartItem& item : this->cartItems) {

        if (item.getProduct()->getId() == product->getId()) {
            item.setQuantity(item.getQuantity() + quantity);
            return;
        }
    }
    this->cartItems.emplace_back(product, quantity);
}

void Cart::removeProduct(const Product* product) {

    auto it = std::remove_if(this->cartItems.begin(), this->cartItems.end(),
        [&](const CartItem& item) {
            return item.getProduct()->getId() == product->getId();
        });

    if (it == this->cartItems.end())    throw std::invalid_argument("Product not found in cart");
    this->cartItems.erase(it, this->cartItems.end());
}

void Cart::updateQuantity(const Product* product, int quantity) {

    if (quantity < 0)   throw std::invalid_argument("Quantity must be non-negative");
    for (CartItem& item : this->cartItems) {

        if (item.getProduct()->getId() == product->getId()) {
            item.setQuantity(quantity);
            return;
        }
    }
    throw std::invalid_argument("Product not found in cart");
}

double Cart::calculateSubTotal() const {

    double total = 0;
    for (const CartItem& item : this->cartItems)    total += item.getProduct()->getPrice() * item.getQuantity();
    return total;
}

const std::vector<CartItem>& Cart::getItems() const {
    return this->cartItems;
}