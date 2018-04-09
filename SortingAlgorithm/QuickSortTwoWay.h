#pragma once

template<class T>
void quick_sort_2(T arr[],int n)
{
	srand(time(nullptr));
	__quick_sort_2(arr, 0, n - 1);
}

template<class T>
void __quick_sort_2(T arr[],int l,int r)
{
	if(r-l<=15)
	{
		insertion_sort(arr, l, r);
		return;
	}
	int p = __parition2(arr, l, r);
	__quick_sort_2(arr, l, p - 1);
	__quick_sort_2(arr, p+1, r);
}

template<class T>
int __parition2(T arr[],int l,int r)
{
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int i = l+1;
	int j = r;
	while (true)
	{
		while (i<=r&&arr[i] < v)
		{
			i++;
		}
		while (j>=l+1&&arr[j] > v)
		{
			j--;
		}
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}