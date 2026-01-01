#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
public:
	virtual void save(const std::string& invoiceText) const = 0;
	virtual ~Storage() = default;
};

#endif