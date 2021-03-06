#include "pch.h"
#include <iostream>
#include "SmartCache.h"
#include "TestData.h"

TestData* create_test_data(int id) {
	return new TestData(id);
}

using ptr_t = std::shared_ptr<TestData>;

int main()
{
	SmartCache<int, TestData, TestData*(*)(int)> cache(create_test_data);
	
	ptr_t test_data1 = cache.get_obj_by_id(3);

	std::cout << *test_data1 << std::endl;
}
