#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <string.h>
# include <stdint.h>


typedef struct Data
{
    std::string name;
    int age;
}					t_data;

class Serializer
{
    public:

        /* Coplian */
        Serializer();
        Serializer(Serializer &rhs);
        Serializer& operator=(const Serializer &rhs);
        virtual ~Serializer();

        /* Methods */
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif