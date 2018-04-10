#pragma once

template <class T>
void merge_sort(T arr[], int n)
{
	__merge_sort(arr, 0, n - 1);
}

template <class T>
void __merge_sort(T arr[], int l, int r)
{
	if (r - l < 15)
	{
		insertion_sort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;
	__merge_sort(arr, l, mid);
	__merge_sort(arr, mid + 1, r);
	if (arr[mid]>arr[mid + 1])
	{
		__merge(arr, l, mid, r);
	}
}

// merge arr[l...mid] and [mid+1...r]
template <class T>
void __merge(T arr[], int l, int mid, int r)
{
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}
	int i = l;
	int j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l])
		{
			arr[k] = aux[i - l];
			i++;
		}
		else
		{
			arr[k] = aux[j - l];
			j++;
		}
	}
}
