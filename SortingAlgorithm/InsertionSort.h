#pragma once

template<class T>
void insertion_sort(T arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		T e = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}

template <class T>
void insertion_sort(T arr[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		T drop_place = arr[i];
		int j;
		for (j = i; j>l&&arr[j - 1]>drop_place; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = drop_place;
	}
}