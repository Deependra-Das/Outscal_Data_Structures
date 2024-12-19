#include <iostream>
using namespace std;

// Function to sort the array using bubble sort algorithm.
void processBubbleSort(int arr[], int n) 
{
    bool swapped;

    do
    {
        swapped = false;

        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                int swap = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = swap;

                swapped = true;
            }
        }
        n--;


    } while (swapped);

}

void displayArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to dynamically allocate an array and fill it with random values.
void fillDynamicArrayWithRandomValues(int** arr, int* n) 
{
    cout << "Enter the size of the array: ";
    cin >> *n;
    *arr = new int[*n];
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < *n; i++) 
    {
        (*arr)[i] = rand() % 1000; // Fill with random numbers between 0 and 999
    }
}

int main() {
    int* arr;
    int n;
    fillDynamicArrayWithRandomValues(&arr, &n);
    cout << "Unsorted array: ";
    displayArray(arr, n);
    processBubbleSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr; // Deallocate dynamically allocated memory
    return 0;
}