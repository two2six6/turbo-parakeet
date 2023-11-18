#include<iostream>
#include<algorithm>
using namespace std;
int  partition(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= pivot)
			j--;
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (i < j && arr[i] <= pivot)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = pivot;
	return i;
}
void quicksort(int arr[], int left, int right)
{
	int i;
	if (left < right)
	{
		i = partition(arr, left, right);
		quicksort(arr, left, i - 1);
		quicksort(arr, i + 1, right);
	}
}
