
#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP
#include "iostream"
#include "string"
#include "iomanip"
#include "limits.h"
#define FLT_MAX 3.402823466e+38F

class ScalarConversion
{
private:
	ScalarConversion();
	ScalarConversion(const ScalarConversion &copy);
	~ScalarConversion();
	ScalarConversion &operator=(const ScalarConversion &copy);
public:
	static void convert(std::string input);
};

#endif
