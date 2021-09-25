#include<iostream>
using namespace std;

void show(int arr[], int n);
void quicksort(int arr[], int n, int left, int right);
int main()
{
    int arr[10001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, n, 0, n - 1);
    show(arr, n);
}
void quicksort(int arr[], int n, int left, int right)
{
    int i, j;
    if(left<right)
    {
        i = left + 1, j = right;
        while(1)
        {
            while(i<right&&arr[i]<arr[left])
                i++;
            while(j>left&&arr[j]>arr[left])
                j--;
            if(i>=j)
                break;
            swap(arr[i], arr[j]);
            i++, j--;
        }
        swap(arr[left], arr[j]);
        quicksort(arr, n, left, j - 1);
        quicksort(arr, n, j + 1, right);
    }
}
void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}