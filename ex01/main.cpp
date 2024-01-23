//
// Created by Yash on 23/1/24.
//

#include "Serializer.hpp"

int main() {
	Data *stc = new(Data);
	Data *tests;
	uintptr_t test;

	stc[0].a = 10;
	stc[0].b = 'b';
	std::cout << stc->a << std::endl;
	std::cout << stc->b << std::endl;

	std::cout << "variable 1 " << stc << std::endl;
	test = Serializer::serialize(stc);
	std::cout << "Serialized to uint " << test << std::endl;
	tests = Serializer::deserialize(test);
	std::cout << "deserialized to data " << tests << std::endl;
}