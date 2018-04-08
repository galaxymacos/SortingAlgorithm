#include <iostream>
#include <string>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSortBottomUp.h"

using namespace std;



int main()
{
	const auto n = 10000;
	auto* arr = sort_test_helper::generate_random_array(n, 0, n);
	auto* arr2 = sort_test_helper::copy_int_array(arr, n);
	auto* arr3 = sort_test_helper::copy_int_array(arr, n);
	auto* arr4 = sort_test_helper::copy_int_array(arr, n);
	sort_test_helper::test_sort("selection sort",selection_sort,arr,n);
	sort_test_helper::test_sort("insertion sort",insertion_sort,arr2,n);
	sort_test_helper::test_sort("bubble sort",bubble_sort,arr3,n);
	sort_test_helper::test_sort("merge sort", merge_sort_bottom_up, arr4, n);
	cin.get();
	delete[]arr;
	delete[]arr2;
	delete[]arr3;
	delete[]arr4;
}












