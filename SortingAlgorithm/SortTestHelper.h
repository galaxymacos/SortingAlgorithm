#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace sort_test_helper
{
	inline int* generate_random_array(const int n, const int range_left, const int range_right)
	{
		assert(range_left < range_right);
		auto* arr = new int[n];
		srand(time(nullptr));
		for(auto i = 0;i<n;i++)
		{
			arr[i] = rand() % (range_right - range_left+1) + range_left;
		}
		return arr;
	}
	
	inline int* generate_nearly_ordered_array(const int n,const int swap_times)
	{
		auto *arr = new int[n];
		for (auto i = 0; i < n; i++)
		{
			arr[i] = i;
		}
		srand(time(nullptr));
		for(auto i = 0;i<swap_times;i++)
		{
			const auto a = rand() % n;
			const auto b = rand() % n;
			swap(arr[a], arr[b]);
		}
		return arr;
	}

	template<class T>
	void print_array(T arr[], const int n)
	{
		for (auto i = 0; i<n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template<class T>
	bool is_sort(T arr[],const int n)
	{
		for(auto i = 0 ; i < n-1;i++)
		{
			if (arr[i + 1] < arr[i])
				return false;
		}
		return true;
	}

	template<class T>
	void test_sort(const string &sort_name,void(*sort)(T[],int), T arr[], int n)
	{
		const auto start_time = clock();
		sort(arr, n);
		const auto end_time = clock();
		assert(is_sort(arr, n));
		cout << sort_name << ": " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
	}

	inline int* copy_int_array(const int* arr,const int n)
	{
		auto* new_arr = new int[n];
		for(auto i = 0;i<n;i++)
		{
			new_arr[i] = arr[i];
		}
		return new_arr;
	}
}