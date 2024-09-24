#include <iostream>
using namespace std;

void deleteElement(int arr[], int n, int delValue);

int main()
{
    int N, delValue;
    cout << "Enter the size (greater than 0) of your array: ";
    cin >> N;

    int arr[N];
    cout << "Enter " << N << " elements:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element you wish to delete: ";
    cin >> delValue;

    deleteElement(arr, N, delValue);

    return 0;
}

void deleteElement(int arr[], int N, int delValue) {

    int delIndex = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == delValue)
        {
            delIndex = i;
            break;
        }
    }

    if (delIndex != -1 && delIndex < N)
    {
        N = N - 1;
        cout << "\nElement found and deleted.\n";
        for (int j = delIndex; j < N; j++)
        {
            arr[j] = arr[j + 1];
        }

        cout << "\nUpdated array: \n";
        for (int i = 0; i < N; i++)
            cout << arr[i] << endl;
    }
    else
    {
        cout << "\nElement not found. No deletion performed.\n";
    }


}
