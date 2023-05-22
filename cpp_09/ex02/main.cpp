#include "PmergeMe.hpp"

void print_vector(std::vector<long> vector)
{
    std::vector<long>::iterator it;
    for(it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << " ";
    }
}

int main(int argc, char **argv)
{
    // Check arg number
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe <number> <number> ..." << std::endl;
        return 1;
    }

    // Fill list
    std::vector<long> vector;
    std::deque<long> deque;
    for(int i = 1; i < argc; i++)
    {
        vector.push_back(std::atof(argv[i]));
        deque.push_back(std::atof(argv[i]));
    }

    // Print unsorted list
    std::cout << BOLD << "before : " << DEFAULT;
    print_vector(vector);
    std::cout << std::endl;

    // Sort containers 

    clock_t start = clock();
    mergeSortVector(&vector, 0, vector.size() - 1);
    clock_t vec_duration = clock() - start;

    start = clock();
    mergeSortDeque(&deque, 0, deque.size() - 1);
    clock_t deq_duration = clock() - start;

    // Print sorted list
    std::cout << BOLD << "after  : " << DEFAULT;
    print_vector(vector);
    std::cout << std::endl;

    // Print process times 
    std::cout << YELLOW << "[vector] Time to process " << vector.size() <<  " elements : ";
    std::cout << vec_duration * 1000 / (double)CLOCKS_PER_SEC << " ms" << DEFAULT << std::endl << std::endl;

    std::cout << YELLOW << "[deque]  Time to process " << vector.size() << " elements : ";
    std::cout << deq_duration * 1000 / (double)CLOCKS_PER_SEC << " ms" << DEFAULT << std::endl;


    return 0;
}