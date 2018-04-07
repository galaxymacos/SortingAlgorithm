#include <iostream>
using namespace std;

void selection_sort(int arr[], int n);

int main()
{
	int unsorted[8] = { 8,6,2,3,1,5,7,4 };
	int min = unsorted[0];
	for(int i = 0 ; i<8;i++)
	{
		min = i;
		for(int j = i+1;j<8;j++)
		{
			if(unsorted[j]<unsorted[min])
			{
				min = j;
			}
		}
		swap(unsorted[i], unsorted[min]);
	}
	for(auto i:unsorted)
	{
		cout << i << " ";
	}
	cin.get();
}

void selection_sort(int arr[], int n)
{
	
}
