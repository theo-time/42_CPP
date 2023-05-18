#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>


class ValueNotFound: public std::exception
{
    public:
        virtual const char* what() const throw()  {return "easyfind: value not found in container";};
};

template<typename T>
typename T::iterator easyfind(T container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFound();
    return std::find(container.begin(), container.end(), value);
}

#endif