#include <iostream>
#include <string>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSortBottomUp.h"
#include "QuickSort.h"
#include "QuickSortTwoWay.h"
#include "QuickSortThreeWays.h"

using namespace std;



int main()
{
	auto n = 1000000;
	auto* arr = sort_test_helper::generate_random_array(n, 0, n);
	auto* arr2 = sort_test_helper::copy_int_array(arr, n);
	auto* arr3 = sort_test_helper::copy_int_array(arr, n);
	auto* arr4 = sort_test_helper::copy_int_array(arr, n);
	cout<<"Test for Random Array, size = 1000000, random range[0,1000000]"<<endl;
	sort_test_helper::test_sort("merge sort", merge_sort, arr, n);
	sort_test_helper::test_sort("quick sort", quick_sort, arr2, n);
	sort_test_helper::test_sort("quick sort two ways", quick_sort_2, arr3, n);
	sort_test_helper::test_sort("quick sort three ways", quick_sort_3, arr4, n);
	cout << "\nTest for Random Nearly Ordered Array, size = 1000000, swap time 100" << endl;
	auto* nearly_ordered_arr = sort_test_helper::generate_nearly_ordered_array(1000000, 100);
	auto* nearly_ordered_arr2 = sort_test_helper::copy_int_array(nearly_ordered_arr, 1000000);
	auto* nearly_ordered_arr3 = sort_test_helper::copy_int_array(nearly_ordered_arr, 1000000);
	auto* nearly_ordered_arr4 = sort_test_helper::copy_int_array(nearly_ordered_arr, 1000000);
	sort_test_helper::test_sort("merge sort", merge_sort, nearly_ordered_arr, 1000000);
	sort_test_helper::test_sort("quick sort", quick_sort, nearly_ordered_arr2, 1000000);
	sort_test_helper::test_sort("two way quick sort", quick_sort_2, nearly_ordered_arr3, 1000000);
	sort_test_helper::test_sort("three way quick sort", quick_sort_3, nearly_ordered_arr4, 1000000);
	cout << "\nTest for Random Array, size = 1000000, random range[0,10]" << endl;
	n = 100000;
	auto* noarr_small_range = sort_test_helper::generate_random_array(n, 0, 10);
	auto* noarr_small_range2 = sort_test_helper::copy_int_array(noarr_small_range,n);
	auto* noarr_small_range3 = sort_test_helper::copy_int_array(noarr_small_range,n);
	auto* noarr_small_range4 = sort_test_helper::copy_int_array(noarr_small_range,n);
	sort_test_helper::test_sort("merge sort", merge_sort, noarr_small_range, n);
	sort_test_helper::test_sort("quick sort", quick_sort, noarr_small_range2, n);
	sort_test_helper::test_sort("two way quick sort", quick_sort_2, noarr_small_range3, n);
	sort_test_helper::test_sort("three way quick sort", quick_sort_3, noarr_small_range4, n);
	
	cin.get();
	delete[]arr;
//	delete[]arr2;
//	delete[]arr3;
}












