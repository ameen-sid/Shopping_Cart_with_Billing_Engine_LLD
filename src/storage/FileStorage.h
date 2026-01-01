#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <string>
#include "Storage.h"

class FileStorage : public Storage {
public:
	void save(const std::string& invoiceText) const override;
};

#endif