#ifndef WHATEVER_H
#define WHATEVER_H

template<typename T>
void swap(T &item1, T &item2)
{
    T tmp = item1;
    item1 = item2;
    item2 = tmp;
}

template<typename T>
const T min(const T &item1, const T &item2)
{
    if (item1 < item2)
        return item1;
    else 
        return item2;
}

template<typename T>
const T max(const T &item1, const T &item2)
{
    if (item1 > item2)
        return item1;
    else 
        return item2;
}

#endif