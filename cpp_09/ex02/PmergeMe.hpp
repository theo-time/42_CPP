#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h> 
#include <ctime>
#include <vector>
#include <deque>
#include <ctime>

#include "Colors.hpp"

void mergeSortVector(std::vector<long> *arr, int low, int high);
void mergeSortDeque(std::deque<long> *arr, int low, int high);

#endif