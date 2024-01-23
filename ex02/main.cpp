
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Base *generate(){
	int random_num = (std::rand() % 3) + 1;

	if (random_num == 1)
		return (new(A));
	else if (random_num == 2)
		return (new(B));
	else
		return (new(C));
}

void identify(Base *ptr){
	try
	{
		if (dynamic_cast<A*>(ptr))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(ptr))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(ptr))
			std::cout << "C" << std::endl;
		else
			std::cout << "Unknown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void identify(Base &ptr){
	if (dynamic_cast<A*>(&ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

int main(){
	srand((unsigned) time(NULL));
	Base *base = NULL;

	identify(base);
	identify(*base);

	delete base;
	return (0);
}