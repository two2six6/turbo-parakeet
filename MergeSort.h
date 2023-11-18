#include<iostream>
#include<algorithm>
using namespace std;
void merge(int arr[], int a[], int left, int mid, int right)
{
	int k = left;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			a[k++] = arr[i++];
		if (arr[i] > arr[j])
			a[k++] = arr[j++];
	}
	while (i <= mid)
		a[k++] = arr[i++];
	while (j <= right)
		a[k++] = arr[j++];
	for (int i = 0; i <= right; i++)
		arr[i] = a[i];
}
void MergeSort(int arr[], int temp[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = left + (right - left) / 2;
		MergeSort(arr, temp, left, mid);
		MergeSort(arr, temp, mid + 1, right);
		merge(arr, temp, left, mid, right);
	}
}
