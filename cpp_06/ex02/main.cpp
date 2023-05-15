#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));
    Base *base1 = generate();
    identify(base1);
    return 0;
}