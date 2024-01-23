
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
	try {
		A& a = dynamic_cast<A&>(*ptr);
		std::cout << "A" << std::endl;
		(void)a;
	}catch(std::exception &e){}
	try {
		B& b = dynamic_cast<B&>(*ptr);
		std::cout << "B" << std::endl;
		(void)b;
	}catch(std::exception &e){}
	try {
		C& c = dynamic_cast<C&>(*ptr);
		std::cout << "C" << std::endl;
		(void)c;
	}catch(std::exception &e){}
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
	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;
	return (0);
}