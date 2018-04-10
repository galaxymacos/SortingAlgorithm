#pragma once

int global_invasion = 0;

template <class T>
long long inversion_count(T arr[], int n)
{
	return __inversion_count(arr, 0, n - 1);

}

template <class T>
long long __inversion_count(T arr[], int l, int r)
{
	if (l >= r)
		return 0;

	int mid = (l + r) / 2;
	long long res1 = __inversion_count(arr, l, mid);
	long long res2 = __inversion_count(arr, mid + 1, r);
	return res1+res2+__merge1(arr, l, mid, r);
}

// merge arr[l...mid] and [mid+1...r]
template <class T>
long long __merge1(T arr[], int l, int mid, int r)
{
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}
	long long res = 0;
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
			res += mid - i + 1;
			j++;
		}
	}
	delete[] aux;
	return res;
}
