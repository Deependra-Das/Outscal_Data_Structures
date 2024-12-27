#include <iostream>
using namespace std;

// Function to perform Counting Sort based on digit place (1s, 10s, 100s, etc.)
void countSort(int arr[], int n, int exponent)
{
    int* output = new int[n];
    int count[10] = { 0 };

    for(int i=0;i<n;i++)
    {
        count[(arr[i] / exponent) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exponent) % 10]-1] = arr[i];
        count[(arr[i] / exponent) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
}

// Function to perform Radix Sort on the array.
void radixSort(int arr[], int n) 
{
    int maxElement = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    for (int exp = 1; maxElement / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

// Function to initiate the Radix Sort process.
void processRadixSort(int arr[], int n) {
    radixSort(arr, n);
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
    processRadixSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr; // Deallocate dynamically allocated memory
    return 0;
}