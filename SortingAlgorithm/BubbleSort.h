#pragma once

template <class T>
void bubble_sort(T arr[], int n)
{
	bool swapped;
	do
	{
		swapped = false;
		for (auto i = 1; i < n; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i - 1], arr[i]);
				swapped = true;
			}
		}
		n--;
	} while (swapped);

}