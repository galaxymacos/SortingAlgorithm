#pragma once

template<class T>
int __parition(T arr[], const int l, const int r)
{
	// pick element from middle to the beginning
	// to avoid the situation which we have a nearly ordered array
	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];
	auto j = l;

	// Purpose: arr[l+1,j] < v; arr[j+1,i) > v
	for (auto i = l + 1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[++j]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

template<class T>
void __quick_sort(T arr[],int l,int r)
{
	if(r-l<=15)
	{
		insertion_sort(arr, l, r);
		return;
	}

	int p = __parition(arr, l, r);
	__quick_sort(arr, l, p - 1);
	__quick_sort(arr, p+1, r);
}

template<class T>
void quick_sort(T arr[],const int n)
{
	srand(time(nullptr));	// randomly pick v
	__quick_sort(arr, 0, n - 1);
}
