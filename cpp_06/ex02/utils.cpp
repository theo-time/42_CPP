#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>


Base *generate(void)
{
    int random = std::rand() % 3;
    if (random == 0)
        return ((Base*) new A());
    else if (random == 1)
        return ((Base*) new B());
    else if (random == 2)
        return ((Base*) new C());
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}


void identify(Base& p);