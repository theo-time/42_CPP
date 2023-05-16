#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
    private:
        T*           _array;
        int           _size;

    public:

        /* Coplian */

        Array<T>()
        {
            _array = NULL;
            _size = 0;
        }

        Array<T>(const unsigned int n)
        {
            _size = n;
            if(_size < 0)
                throw Array<T>::IndexOutOfRange();
            _array = new T[n];
        }

        Array<T>(const Array<T> &rhs)
        {
            _size = rhs.size();
            _array = new T[_size];
            for(int i = 0; i < _size; i++)
                _array[i] = rhs[i];
        }

        Array<T> &operator=(const Array<T> &rhs)
        {
            if(this == &rhs)
                return *this;
            if(this->_size > 0)
                delete[] _array;
            _size = rhs.size();
            _array = new T[_size];
            for(int i = 0; i < _size; i++)
                _array[i] = rhs[i];
            return *this;
        }

        ~Array<T>()
        {
            if(_size > 0)
                delete[] _array;
        }

        /* Methods */
        T &operator[](const int i) const
        {
            if(i >= _size || i < 0)
                throw Array<T>::IndexOutOfRange();
            return _array[i];
        }

        unsigned int size() const
        {
            return (_size);
        }


        /* Exceptions */
        class IndexOutOfRange: public std::exception
        {
            public:
                virtual const char* what() const throw() {return "array: index out of range";};
        };
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &rhs)
{
    for(unsigned int i = 0; i < rhs.size(); i++)
        out << rhs[i] << std::endl;
    return out;
}

#endif