#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

// Function to merge two sorted sub-arrays in place.
void inPlaceMerge(int arr[], int left, int mid, int right) 
{
    int start = mid + 1;
    if (arr[mid] <= arr[start])
    {
        return;
    }
    while (left <= mid && start <= right)
    {
        if (arr[left] <= arr[start])
        {
            left++;
        }
        else
        {
            int temp = arr[start];
            for (int k = start; k > left; k--)
            {
                arr[k] = arr[k - 1];
            }
            arr[left] = temp;
            left++;
            mid++;
            start++;
        }
    }
}

// Function to recursively sort the array using Merge Sort.
void inPlaceMergeSort(int arr[], int left, int right) 
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        inPlaceMergeSort(arr, left, mid);
        inPlaceMergeSort(arr, mid + 1, right);

        inPlaceMerge(arr, left, mid, right);

    }

}

// Function to initiate the Merge Sort process.
void processInPlaceMergeSort(int arr[], int n) {
    if (n > 1) {
        inPlaceMergeSort(arr, 0, n - 1);
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
    processInPlaceMergeSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr; // Deallocate dynamically allocated memory
    return 0;
}