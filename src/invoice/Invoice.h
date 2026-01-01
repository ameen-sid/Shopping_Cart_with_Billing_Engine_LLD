#ifndef INVOICE_H
#define INVOICE_H

#include "../billdata/BillData.h"
#include <string>

class Invoice {
public:
	void printToConsole(const BillData& billdata) const;
	std::string generateInvoiceText(const BillData& billdata) const;
};

#endif