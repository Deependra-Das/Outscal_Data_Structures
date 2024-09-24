#include <iostream>
using namespace std;

void findPeakElement(int arr[], int n);

int main()
{
    int N;
    cout << "Enter the size (greater than 0) of the array : ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    findPeakElement(arr, N);

    return 0;
}

void findPeakElement(int arr[], int N) {
    cout << "Indices of peak elements: ";

    for (int i = 0; i < N; i++)
    {
        if ((i == 0 || arr[i] >= arr[i - 1]) && (i == N - 1 || arr[i] >= arr[i + 1]))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
