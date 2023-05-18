#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>   

class Span
{
    private:
        std::vector<int>    _list;
        int                 _sizeMax;
    
    public:

        /* Coplian */
        Span();
        Span(Span &rhs);
        Span& operator=(const Span &rhs);
        virtual ~Span();

        /* Constructeurs */
        Span(int N);

        /* Methods */
        void                addNumber(int n);
        void                addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned long       shortestSpan();
        unsigned long       longestSpan();

        /* Getters and Setters */
        std::vector<int>    getList() const;
        int                 getSizeMax() const;

        /* Exceptions */       

        class ContainerIsFull: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class ContainerIsEmpty: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class ContainsOnlyOne: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif