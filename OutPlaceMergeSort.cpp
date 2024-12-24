#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted halves of the array into a single sorted array.
void merge(int arr[], int left, int mid, int right) 
{
     int size1 = mid - left + 1;
     int size2 = right - mid;

     vector<int> leftArr(size1), rightArr(size2);

    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++)
    {
        rightArr[i] = arr[mid + 1+ i];
    }

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

}

// Function to recursively divide the array and merge the sorted halves.
void mergeSort(int arr[], int left, int right) 
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
        
    }
        
}

// Function to initiate the merge sort process.
void processMergeSort(int arr[], int size) 
{
    if (size > 1)
    {
       mergeSort(arr, 0, size - 1);
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to dynamically allocate an array and fill it with random values.
void fillDynamicArrayWithRandomValues(int** arr, int* n) {
    cout << "Enter the size of the array: ";
    cin >> *n;
    *arr = new int[*n];
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < *n; i++) {
        (*arr)[i] = rand() % 1000; // Fill with random numbers between 0 and 999
    }
}

int main() {
    int* arr;
    int n;
    fillDynamicArrayWithRandomValues(&arr, &n);
    cout << "Unsorted array: ";
    displayArray(arr, n);
    processMergeSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr; // Deallocate dynamically allocated memory
    return 0;
}
