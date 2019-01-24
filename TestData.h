#pragma once
#include <iostream>
#include <string>
#include <ostream>

class TestData {
private:
	std::string message;

public:
	TestData(int id) : message("number: " + std::to_string(id)) {}

	friend std::ostream& operator << (std::ostream &os, const TestData &test_data) {
		os << test_data.message << std::endl;
		return os;
	}
};