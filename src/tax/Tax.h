#ifndef TAX_H
#define TAX_H

class Tax {
private:
	double taxRate;

public:
	explicit Tax(double taxRate);

	double calculateTax(double amountAfterDiscount) const;

	void setTaxRate(double taxRate);
};

#endif