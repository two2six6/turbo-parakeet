#include <iostream>
#include <vector>
using namespace std;
long long merge(vector<int>& arr, int left, int mid, int right) //����������鲢��һ�����飬������
{
    vector<int> temp(right - left + 1);//������ʱ����洢�鲢�������
    int i = left;
    int j = mid + 1;
    int k = 0;
    long long inversions = 0;
    while (i <= mid && j <= right) //����ָ��ͬʱ�ƶ�
    {
        if (arr[i] <= arr[j]) {//�����С���ұ���������ִ�����ʱ����
            temp[k++] = arr[i++];
        }
        else {//����ߴ����ұߣ����ұ���������ʱ����ͬʱ������Ϊmid-i+1
            inversions += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }//����while��ʣ�µ����ִ�����ʱ����
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }//����ʱ�������arr��
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    return inversions;//����������
}
long long mergeSort(vector<int>& arr, int left, int right) {//���й鲢����
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    long long inversions = 0;
    inversions += mergeSort(arr, left, mid);//�ݹ����������������
    inversions += mergeSort(arr, mid + 1, right);//�ݹ����������������
    inversions += merge(arr, left, mid, right);//�ݹ�����������ϲ������������
    return inversions;
}
long long countInversions(vector<int>& arr) {//����������
    return mergeSort(arr, 0, arr.size() - 1);
}
int main() {
    vector<int> arr = {6,2,3,1};
    long long count = countInversions(arr);
    cout << "Inversion count: " << count << endl;  
    return 0;
}
