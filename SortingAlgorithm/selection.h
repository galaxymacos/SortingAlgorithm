#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;

// partition 过程, 和快排的partition一样
// 思考: 双路快排和三路快排的思想能不能用在selection算法中? :)
template <typename T>
int __partition(T arr[], int l, int r) {

	int p = rand() % (r - l + 1) + l;
	swap(arr[l], arr[p]);

	int j = l; //[l+1...j] < p ; [lt+1..i) > p
	for (int i = l + 1; i <= r; i++)
		if (arr[i] < arr[l])
		{
			swap(arr[i], arr[j+1]);
			j++;
		}
			

	swap(arr[l], arr[j]);

	return j;
}

// 求出arr[l...r]范围里第k小的数
template <typename T>
int __selection(T arr[], int l, int r, int k) {

	if (l == r)
		return arr[l];

	// partition之后, arr[p]的正确位置就在索引p上
	int p = __partition(arr, l, r);

	if (k == p)    // 如果 k == p, 直接返回arr[p]
		return arr[p];
	else if (k < p)    // 如果 k < p, 只需要在arr[l...p-1]中找第k小元素即可
		return __selection(arr, l, p - 1, k);
	else // 如果 k > p, 则需要在arr[p+1...r]中找第k-p-1小元素
		 // 注意: 由于我们传入__selection的依然是arr, 而不是arr[p+1...r],
		 //       所以传入的最后一个参数依然是k, 而不是k-p-1
		return __selection(arr, p + 1, r, k);
}

// 寻找arr数组中第k小的元素
// 注意: 在我们的算法中, k是从0开始索引的, 即最小的元素是第0小元素, 以此类推
// 如果希望我们的算法中k的语意是从1开始的, 只需要在整个逻辑开始进行k--即可, 可以参考selection2
template <typename T>
int selection(T arr[], int n, int k) {

	assert(k >= 0 && k < n);

	srand(time(NULL));
	return __selection(arr, 0, n - 1, k);
}

// 寻找arr数组中第k小的元素, k从1开始索引, 即最小元素是第1小元素, 以此类推
template <typename T>
int selection2(T arr[], int n, int k) {

	return selection(arr, n, k - 1);
}