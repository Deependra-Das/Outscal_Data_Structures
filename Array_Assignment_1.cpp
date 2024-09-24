
#include <iostream>
using namespace std;

int main()
{
	int ArrValue[15];

	//Initializing the Array Data
	for (int i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
		{
			ArrValue[i] = i * 2;
		}
		else
		{
			ArrValue[i] = i * 3;
		}
	}

	//Displaying the Array Data
	for (int i = 0; i < 15; i++)
	{
		cout << ArrValue[i] << endl;
	}
}