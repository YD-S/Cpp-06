
#include "ScalarConversion.hpp"

 static bool IsChar(std::string input) {
	if (input.length() == 1 && !isdigit(input[0]))
		return true;
	else
		return false;
}

 static bool IsInt(std::string input) {
	for (unsigned long i = 0; i < input.length(); i++) {
		if (i == 0 && input[i] == '-')
			continue;
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

static bool IsFloat(std::string input) {
	int dot = 0;
	int f = 0;
	for (unsigned long i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			dot++;
		else if (input[i] == 'f')
			f++;
		else if (input[i] < '0' || input[i] > '9')
			return false;
	}
	if (dot == 1 && f == 1 && input[input.length() - 1] == 'f')
		return true;
	else
		return false;
}

static bool IsDouble(std::string input) {
	int dot = 0;
	for (unsigned long i = 0; i < input.length(); i++) {
		if (i == 0 && input[i] == '-')
			continue;
		if (input[i] == '.')
			dot++;
		else if (!isdigit(input[i]))
			return false;
	}
	if (dot == 1)
		return true;
	else
		return false;
}

 static char GetType(std::string input) {
	if (input == "nan" || input == "nanf")
		return 'n';
	else if (input == "-inf" || input == "-inff")
		return '-';
	else if (input == "+inf" || input == "+inff")
		return '+';
	else if (IsChar(input))
		return 'c';
	else if (IsInt(input))
		return 'i';
	else if (IsFloat(input))
		return 'f';
	else if (IsDouble(input))
		return 'd';
	else
		return '0';
}

static void ConvertChar(std::string input) {
	char c = input[0];
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void ConvertInt(std::string input) {
	try{
		int i = std::stoi(input);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
	std::cout << "char: ";
	if (i >= 0 && i <= 127)
		if (isprint(i))
			std::cout << static_cast<char>(i) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}catch(const std::exception& e){
		std::cout << "Invalid ARG" << std::endl;
		exit(1);
	}
}

static void ConvertFloat(std::string input) {
	try{	
		float f = std::stof(input);
		double d = static_cast<double>(f);
		std::cout << "char: ";
		if (f >= 0 && f <= 127)
			if (isprint(f))
				std::cout << static_cast<char>(f) << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		if (f >= INT_MIN && f <= INT_MAX)
			std::cout << static_cast<int>(f) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}catch(const std::exception& e){
		std::cout << "Invalid ARG" << std::endl;
		exit(1);
	}
}

static void ConvertDouble(std::string input) {
	try{
		double d = std::stod(input);
		std::cout << "char: ";
		if (d >= 0 && d <= 127)
			if (isprint(d))
				std::cout << static_cast<char>(d) << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		if (d >= INT_MIN && d <= INT_MAX)
			std::cout << static_cast<int>(d) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: ";
		if (d >= -FLT_MAX && d <= FLT_MAX)
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}catch(const std::exception& e){
		std::cout << "Invalid ARG" << std::endl;
		exit(1);
	}
}

static void ConvertNan() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void ConvertNegInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

static void ConvertInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

 void ScalarConversion::convert(std::string input) {
	char type = GetType(input);
	 switch (type) {
		case 'c':
			std::cout << "the input is a char" << std::endl;
			ConvertChar(input);
			break;
		case 'i':
			std::cout << "the input is an int" << std::endl;
			ConvertInt(input);
			break;
		case 'f':
			std::cout << "the input is a float" << std::endl;
			ConvertFloat(input);
			break;
		case 'd':
			std::cout << "the input is a double" << std::endl;
			ConvertDouble(input);
			break;
		case 'n':
			 std::cout << "the input is a nan or nanf" << std::endl;
			 ConvertNan();
			 break;
		case '-':
			std::cout << "the input is -inf or -inff" << std::endl;
			 ConvertNegInf();
			break;
		case '+':
			std::cout << "the input is +inf or +inff" << std::endl;
			 ConvertInf();
			break;
		default:
			std::cout << "Error: Invalid input" << std::endl;
			break;
	 }
}