#include <iostream>
#include <string>

#include "iter.h"

void int_printer(int &nb)
{
    std::cout << nb << std::endl;
}

int main( void ) {
    int arr[5] = {0,1,2,3,4};

    iter<int>(arr, 5, int_printer);
    return 0;
}