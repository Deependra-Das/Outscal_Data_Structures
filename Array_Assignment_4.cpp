#include <iostream>
using namespace std;

int minJumps(int nums[], int n);

int main()
{
    int N;
    do {
        cout << "Enter the size (b/w 1 & 10000) of your array: ";
        cin >> N;
        if (N < 1 || N > 10000)
        {
            (void)system("clear");
            cout << "\nInvalid input." << endl;
        }
    } while (N < 1 || N > 10000);

    int nums[N];
    cout << "Enter " << N << " elements (b/w 0 & 1000):" << endl;
    for (int i = 0; i < N; i++)
    {
        do {
            cin >> nums[i];
            if (nums[i] < 0 || nums[i] >= 1000)
            {
                cout << "Invalid input. Please enter elements (b/w 0 & 1000):" << endl;
            }
        } while (nums[i] < 0 || nums[i] >= 1000);
    }

    cout << "Array Values: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }

    cout << "\nMinimum jumps needed to reach the last index: " << minJumps(nums, N);

    return 0;
}

int minJumps(int nums[], int N)
{
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        farthest = max(farthest, i + nums[i]);

        if (i == currentEnd)
        {
            jumps++;
            currentEnd = farthest;
            if (currentEnd >= N - 1)
            {
                break;
            }
        }
    }

    return jumps;
}

