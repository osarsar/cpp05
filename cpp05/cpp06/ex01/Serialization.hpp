#include <iostream>
#include <cstdint>

class Data
{
    public:
        int data1;
        double data2;

    public:
        Data();
        ~Data();
        Data(int d1, double d2);
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

