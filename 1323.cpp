#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>& arr, int pos, int n);
int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    arr.resize(n);
    backtrack(arr,0,n); 
}
void backtrack(vector<int>& arr, int pos, int n)
{
    if(pos==n)
    {
        for(int i=0; i<arr.size(); i++)
        {
            cout<<arr[i];
        } 
        cout<<endl;
        return;
    }
    arr[pos]=0;
    backtrack(arr,pos+1,n);
    arr[pos]=1;
    backtrack(arr,pos+1,n);
}
