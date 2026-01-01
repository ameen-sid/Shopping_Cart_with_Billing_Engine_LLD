#include "./cart/Cart.h"
#include "./billing/Billing.h"
#include "./invoice/Invoice.h"
#include "./storage/FileStorage.h"
#include "./tax/Tax.h"
#include "./discount/FlatDiscount.h"
#include "./discount/PercentageDiscount.h"
#include "./ui/UserInteraction.h"
#include <vector>

int main() {
	Product laptop(1, "Laptop", 52000);
	Product mouse(2, "Mouse", 800);
	Product keyboard(3, "Keyboard", 1500);
	Product ac(4, "Air Condition", 55000);
	Product monitor(5, "Monitor", 13000);
	Product harddisk(6, "Hard Disk", 700);
	Product desk(7, "Work Desk", 2100);
	std::vector<Product> products{ laptop, mouse, keyboard, ac, monitor, harddisk, desk };

	Cart cart;
	Billing billing;
	Invoice invoice;
	FileStorage storage;
	Tax tax(18);

	FlatDiscount flat(5000);
	PercentageDiscount percent(10);
	std::vector<Discount*> discounts = { &flat, &percent };

	UserInteraction ui(
		cart,
		billing,
		invoice,
		storage,
		tax,
		discounts,
		products
	);

	ui.start();
	return 0;
}