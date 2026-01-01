#include "FileStorage.h"
#include <fstream>
#include <stdexcept>

void FileStorage::save(const std::string& invoiceString) const {

	std::ofstream file("invoice.txt", std::ios::trunc);

	if (!file.is_open())	throw std::runtime_error("Failed to open invoice.txt for writing");
	file << invoiceString;
	file.close();
}