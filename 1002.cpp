#include<iostream>
#include<vector>

using namespace std;
void merge(int arr[], int l1, int r1, int l2, int r2);
void mergesort(int arr[], int start, int end);
int main()
{
    int arr[10000];
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    mergesort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;
}
void mergesort(int arr[], int start, int end)
{
    if(start<end)
    {
        int mid = (start + end)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, mid + 1, end);
    }
}
void merge(int arr[], int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2, n = r2 - l1 + 1, k = 0;
    vector<int> tmp(n);
    while(i<=r1&&j<=r2)
    {
        if(arr[i]<arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while(i<=r1)
        tmp[k++] = arr[i++];
    while(j<=r2)
        tmp[k++] = arr[j++];
    for (int l = 0; l < n; l++)
        arr[l1 + l] = tmp[l];
}