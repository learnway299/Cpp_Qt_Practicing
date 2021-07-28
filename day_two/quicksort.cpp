#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*使用C++实现quick sort算法;
尽量使用到课程中介绍的C++特性；
支持不同数据类型；
*/

// 函数模板
template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
	if (start >= end)
		return;
	T mid = arr[end];
	int left = start, right = end - 1;
	//在整个范围内搜寻比枢纽元值小或大的元素，然后将左侧元素与右侧元素交换
	while (left < right) {
		//试图在左侧找到一个比枢纽元更大的元素
		while (arr[left] < mid && left < right)
			left++;
		//试图在右侧找到一个比枢纽元更小的元素
		while (arr[right] >= mid && left < right)
			right--;
		//交换元素
		std::swap(arr[left], arr[right]);
	}
	if (arr[left] >= arr[end])
		std::swap(arr[left], arr[end]);
	else
		left++;
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}

template <typename T>
void quick_sort(T arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}

int main() {
	int flg;
	int n, i;
	while (1) {
		std::cout << "若待排序数组元素类型为整数，输入1；为浮点数输入2" << std::endl;
		std::cin >> flg;
		if (flg == 1) {
			std::cout << "输入需要排序的元素个数" << std::endl;
			std::cin >> n;
			//int* arr = malloc(n * sizeof(int));
			int* arr = new int[n];
			printf("请依次输入%d个元素\n", n);
			for (i = 0; i < n; i++)
				std::cin >> arr[i];
			printf("排序前：\n");
			for (i = 0; i < n; i++)
				std::cout << arr[i] << " ";
			quick_sort(arr, n);
			printf("\n排序后：\n");
			for (i = 0; i < n; i++)
				std::cout << arr[i] << " ";
			std::cout << std::endl;
			delete(arr);
		}
		else {
			std::cout << "输入需要排序的元素个数" << std::endl;
			std::cin >> n;
			//float* arr1 = malloc(n * sizeof(float));
			float* arr1 = new float[n];
			printf("请依次输入%d个元素\n", n);
			for (i = 0; i < n; i++)
				std::cin >> arr1[i];
			printf("排序前：\n");
			for (i = 0; i < n; i++)
				std::cout << arr1[i] << " ";
			quick_sort(arr1, n);
			printf("\n排序后：\n");
			for (i = 0; i < n; i++)
				std::cout << arr1[i] << " ";
			std::cout << std::endl;
			delete(arr1);
		}
	}
	return 0;
}
