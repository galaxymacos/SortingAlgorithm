#pragma once
#include "MergeSort.h"
#include <algorithm>
using namespace std;

template<class T>
void merge_sort_bottom_up(T arr[], const int n)
{
	for (auto sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i + sz<n; i += sz + sz)
		{
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}
}