#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template<class T>
void quick_sort_3(T arr[], int n)
{
	srand(time(nullptr));
	__quick_sort_3(arr, 0, n - 1);
}

template<class T>
void __quick_sort_3(T arr[], int l, int r)
{
	if (r - l <= 15)
	{
		insertion_sort(arr, l, r);
		return;
	}
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int lt = l;
	int gt = r+1;
	int i = l + 1;
	while (i < gt)
	{
			if (arr[i] < v)
			{
				swap(arr[i], arr[lt+1]);
				lt++;
				i++;
			}
			else if (arr[i] > v)
			{
				swap(arr[gt - 1], arr[i]);
				gt--;
			}
			else
			{
				i++;
			}
	}
	
	swap(arr[l], arr[lt]);

	__quick_sort_3(arr, l, lt);
	__quick_sort_3(arr, gt, r);
}