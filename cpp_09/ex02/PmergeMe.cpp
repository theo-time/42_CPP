#include "PmergeMe.hpp"

static std::vector<long> mergeVector(std::vector<long> arr, int low, int mid, int high)
{
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;  
    
    // Creating two temp vectors
    std::vector<long> leftArr, rightArr;
    
    // Copying values from the original array
    for (int a = 0; a < lengthLeft; a++) {
        leftArr.push_back(arr[low + a]);
    }
    for (int a = 0; a < lengthRight; a++) {
        rightArr.push_back(arr[mid + 1 + a]);
    }

    // Merging the temp arrays back into the actual array.
    i = 0; 
    j = 0; 
    k = low; 

    while (i < lengthLeft && j < lengthRight) {
        // Checking and placing the smaller number of both temp arrays into the main array.
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // After the successful execution of the above loop
    // copying the remaining elements of the left subarray (if remaining).
    while (i < lengthLeft) {
        arr[k] = leftArr[i];
        k++;
        i++;
    }

    // Copying the remaining elements of the right sub array (if remaining).
    while (j < lengthRight) {
        arr[k] = rightArr[j];
        k++;
        j++;
    }

    return arr;
}

void mergeSortVector(std::vector<long> *arr, int low, int high)
{
    int mid;
    
    if(low < high)
    {
        // Calculating mid
        mid =  (low + high) / 2;

        // Recursive call
        mergeSortVector(arr, low, mid);
        mergeSortVector(arr, mid + 1, high);

        // Merge arrays
        *arr = mergeVector(*arr, low, mid, high);
    }
}



static std::deque<long> mergeDeque(std::deque<long> arr, int low, int mid, int high)
{
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;  
    
    // Creating two temp vectors
    std::vector<long> leftArr, rightArr;
    
    // Copying values from the original array
    for (int a = 0; a < lengthLeft; a++) {
        leftArr.push_back(arr[low + a]);
    }
    for (int a = 0; a < lengthRight; a++) {
        rightArr.push_back(arr[mid + 1 + a]);
    }

    // Merging the temp arrays back into the actual array.
    i = 0; 
    j = 0; 
    k = low; 

    while (i < lengthLeft && j < lengthRight) {
        // Checking and placing the smaller number of both temp arrays into the main array.
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // After the successful execution of the above loop
    // copying the remaining elements of the left subarray (if remaining).
    while (i < lengthLeft) {
        arr[k] = leftArr[i];
        k++;
        i++;
    }

    // Copying the remaining elements of the right sub array (if remaining).
    while (j < lengthRight) {
        arr[k] = rightArr[j];
        k++;
        j++;
    }

    return arr;
}

void mergeSortDeque(std::deque<long> *arr, int low, int high)
{
    int mid;
    
    if(low < high)
    {
        // Calculating mid
        mid =  (low + high) / 2;

        // Recursive call
        mergeSortDeque(arr, low, mid);
        mergeSortDeque(arr, mid + 1, high);

        // Merge arrays
        *arr = mergeDeque(*arr, low, mid, high);
    }
}
