#include "Serialization.hpp"

Data::Data()
{
    std::cout << "Data: Constructor called" << std::endl;
}

Data::~Data()
{
    std::cout << "Data: Destructor called" << std::endl;
}

Data::Data(int d1, double d2) : data1(d1), data2(d2) 
{
    std::cout << "Data: Constructor copy called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) 
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) 
{
    return reinterpret_cast<Data*>(raw);
}

int main() {
    // Create a Data object
    Data* originalData = new Data(42, 3.14);

    // Serialize the pointer to uintptr_t
    uintptr_t serializedPtr = Serializer::serialize(originalData);

    // Deserialize uintptr_t to a pointer
    Data* deserializedData = Serializer::deserialize(serializedPtr);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserializedData == originalData) {
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Original Data: " << originalData->data1 << ", " << originalData->data2 << std::endl;
    } else {
        std::cerr << "Serialization and deserialization failed." << std::endl;
    }

    // Clean up memory
    delete originalData;

    return 0;
}
