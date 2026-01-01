#include "UserInteraction.h"
#include <iostream>
#include <string>

UserInteraction::UserInteraction(
	Cart& cart,
	Billing& billing,
	Invoice& invoice,
	Storage& storage,
	Tax& tax,
	std::vector<Discount*>& discounts,
	std::vector<Product>& products
)
	:	cart(cart),
		billing(billing),
		invoice(invoice),
		storage(storage),
		tax(tax),
		discounts(discounts),
		products(products)
{}

void UserInteraction::listProducts() {

	std::cout << "\n--- Products ---\n";
	for (Product product : this->products)	std::cout << product.getId() << ". " << product.getName() << " - Rs. " << product.getPrice() << "\n";
}

void UserInteraction::addProduct() {

	int id, qty;
	std::cout << "Product ID: ";
	std::cin >> id;
	std::cout << "Quantity: ";
	std::cin >> qty;

	try {

		std::string name;
		double price;
		for (Product product : this->products) {
			if (product.getId() == id) {

				name = product.getName();
				price = product.getPrice();
				Product* product = new Product(id, name, price);
				cart.addProduct(product, qty);
				std::cout << "Product added\n";
			}
		}
	} catch(const std::exception& e) {
		std::cout << e.what() << "\n";
	}
}

void UserInteraction::removeProduct() {

	int id;
	std::cout << "Product ID to remove: ";
	std::cin >> id;

	try {
		for (const CartItem& item : cart.getItems()) {
			if (item.getProduct()->getId() == id) {

				cart.removeProduct(item.getProduct());
				std::cout << "Product removed\n";
				break;
			}
		}
	} catch(const std::exception e) {
		std::cout << e.what() << "\n";
	}
}

void UserInteraction::generateBill() {

	try {

		BillData bill = billing.generateBill(cart, discounts, tax);
		invoice.printToConsole(bill);

		std::string text = invoice.generateInvoiceText(bill);
		storage.save(text);

		std::cout << "\nInvoice saved to invoice.txt\n";
	} catch(const std::exception& e) {
		std::cout << e.what() << "\n";
	}
}

void UserInteraction::start() {

	int choice;
	while (true) {

		std::cout << "\n--- MENU ---\n";
		std::cout << "1. List Products\n";
		std::cout << "2. Add Product\n";
		std::cout << "3. Remove Product\n";
		std::cout << "4. Generate Bill\n";
		std::cout << "5. Exit\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		if (!std::cin) {

			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input\n";
			continue;
		}

		switch (choice) {

			case 1:
				this->listProducts();
				break;
			case 2:
				this->addProduct();
				break;
			case 3:
				this->removeProduct();
				break;
			case 4:
				this->generateBill();
				break;
			case 5:
				std::cout << "Exiting...\n";
				exit(0);
			default:
				std::cout << "Invalid choice\n";
		}
	}
}