#include <iostream>
#include <vector>
using namespace std;
long long merge(vector<int>& arr, int left, int mid, int right) //将两个数组归并到一个数组，并计数
{
    vector<int> temp(right - left + 1);//创建临时数组存储归并后的数组
    int i = left;
    int j = mid + 1;
    int k = 0;
    long long inversions = 0;
    while (i <= mid && j <= right) //两边指针同时移动
    {
        if (arr[i] <= arr[j]) {//若左边小于右边则将左边数字存入临时数组
            temp[k++] = arr[i++];
        }
        else {//若左边大于右边，将右边数存入临时数组同时逆序数为mid-i+1
            inversions += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }//两个while将剩下的数字存入临时数组
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }//将临时数组存入arr中
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    return inversions;//返回逆序数
}
long long mergeSort(vector<int>& arr, int left, int right) {//进行归并排序
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    long long inversions = 0;
    inversions += mergeSort(arr, left, mid);//递归求左数组的逆序数
    inversions += mergeSort(arr, mid + 1, right);//递归求右数组的逆序数
    inversions += merge(arr, left, mid, right);//递归求两个数组合并数组的逆序数
    return inversions;
}
long long countInversions(vector<int>& arr) {//函数求数组
    return mergeSort(arr, 0, arr.size() - 1);
}
int main() {
    vector<int> arr = {6,2,3,1};
    long long count = countInversions(arr);
    cout << "Inversion count: " << count << endl;  
    return 0;
}
