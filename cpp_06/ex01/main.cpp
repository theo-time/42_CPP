#include <iostream>
#include <string>
#include <stdint.h>

#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    uintptr_t ptr = Serializer::serialize(data);
    Data *data_reserialized = Serializer::deserialize(ptr);
    std::cout << "data : " << data << std::endl;
    std::cout << "serialized : " << ptr << std::endl;
    std::cout << "derialized : " << data_reserialized << std::endl;
    return 0;
}