#pragma once
#include <iostream>
#include <ctime>
int look_for = 4000;

template<class T>
int rank_element(T arr[],int n)
{
	assert(look_for >= 0 && look_for < n);
	srand(time(nullptr));
	return __rank_element(arr, 0,n-1);
}

template<class T>
int __rank_element(T arr[], int l, int r)
{
	if (l == r)
		return arr[l];

	int p = __ranking(arr, l, r);
	if (p == look_for)
		return arr[p];
	else if(p>look_for)
		return __rank_element(arr, l, p-1);
	else
		return __rank_element(arr, p + 1, r);
}

template<class T>
int __ranking(T arr[],int l,int r)
{
	swap(arr[l], arr[rand() % (r - l + 1) + l ]);
	T v = arr[l];
	int i = l+1;
	int j = r;
	while(true)
	{
		while(arr[i]<v&&i<=r)
		{
			i++;
		}
		while(arr[j]>v&&j>=l+1)
		{
			j--;
		}
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		j--;
		i++;
	}
	swap(arr[l], arr[j]);
	return j;
}