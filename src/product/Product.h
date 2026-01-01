#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
	int id;					// assumes user give unique id in input
	std::string name;		// assumes user give unique name in input
	double price;

public:
	Product(int id, const std::string& name, double price);

	int getId() const;
	std::string getName() const;
	double getPrice() const;
};

#endif