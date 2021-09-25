#include<iostream>
using namespace std;
bool search(int arr[], int start, int end, int aim);
int main()
{
    int arr[10000];
    int arrsize, numsize;
    cin >> arrsize;
    for (int i = 0; i < arrsize; i++)
        cin >> arr[i];
    cin >> numsize;
    for (int i = 0; i < numsize; i++)
    {
        int aim;
        cin >> aim;
        if(search(arr,0,arrsize-1,aim))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
bool search(int arr[], int start, int end, int aim)
{
    if(end==start)
    {
        if(arr[end]==aim)
            return true;
        else
            return false;
    }
    int mid = (start + end) >> 1;
    if(arr[mid]==aim)
        return true;
    else if(arr[mid]>aim)
        return search(arr, start, mid, aim);
    else
    {
        return search(arr, mid + 1, end, aim);
    }
    
}