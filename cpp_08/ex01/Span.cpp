#include "Span.hpp"


/* Coplian */
Span::Span()
{
    _sizeMax = 10;
}

Span::Span(Span &rhs)
{
    _sizeMax = rhs.getSizeMax();
    _list = rhs.getList();
}

Span& Span::operator=(const Span &rhs)
{
    _sizeMax = rhs.getSizeMax();
    _list = rhs.getList();
    return *this;
}

Span::~Span()
{

}

/* Constructeurs */
Span::Span(int N)
{
    _sizeMax = N;
}

/* Methods */
void Span::addNumber(int n)
{
    if((unsigned long)_sizeMax == _list.size())
        throw Span::ContainerIsFull();
    _list.push_back(n);
}

void Span::addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if((unsigned long)_sizeMax < _list.size() + std::distance(begin, end))
        throw Span::ContainerIsFull();
    _list.insert(_list.end(), begin, end);
}

unsigned long Span::shortestSpan()
{
    unsigned long minSpan = -1;
    int currentSize = _list.size();
    if(currentSize == 0)
        throw Span::ContainerIsEmpty();
    if(currentSize == 1)
        throw Span::ContainsOnlyOne();
    sort(_list.begin(), _list.end());
    for(int i = 0; i < currentSize; i++)
    {
        if((unsigned long) (_list[i+1] - _list[i]) < minSpan)
            minSpan = _list[i+1] - _list[i];
        if(minSpan == 0)
            break;
    }
    return minSpan;
}

unsigned long Span::longestSpan()
{
    if(_list.size() == 0)
        throw Span::ContainerIsEmpty();
    return( *max_element(_list.begin(), _list.end()) - *min_element(_list.begin(), _list.end()));
}

/* Getters and setters */

std::vector<int>  Span::getList() const {return _list;};
int  Span::getSizeMax() const {return _sizeMax;};

/* Exceptions */

const char* Span::ContainerIsFull::what() const throw()
{
    return "Span: the container is full";
}

const char* Span::ContainerIsEmpty::what() const throw()
{
    return "Span: the container is empty";
}

const char* Span::ContainsOnlyOne::what() const throw()
{
    return "Span: the container has only one element";
}