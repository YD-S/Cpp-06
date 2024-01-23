

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

typedef struct Data
{
	int a;
	char b;
} Data ;

class Serializer
{
private:
	Serializer();
public:
	~Serializer();
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};


#endif
