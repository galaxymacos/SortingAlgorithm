#include <iostream>
#include <string>
#include "SortTestHelper.h"
#include "SelectionSort.h"
//#include "MergeSort.h"
//#include "InsertionSort.h"
//#include "BubbleSort.h"
//#include "MergeSortBottomUp.h"
//#include "QuickSort.h"
//#include "QuickSortTwoWay.h"
//#include "QuickSortThreeWays.h"
#include "InversionCount.h"
#include "RankElementInArray.h"
#include "selection.h"

using namespace std;



int main()
{
	auto n = 1000000;
	auto* arr = sort_test_helper::generate_random_array(n, 0, n);
	auto* arr2 = sort_test_helper::copy_int_array(arr, n);

	cout << "rank 4000 element is ";
	cout << selection(arr, n, 4000) << endl;
	cout << rank_element(arr2, n) << endl;
	cin.get();
}











