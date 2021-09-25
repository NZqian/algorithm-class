#include <iostream>
#include <limits.h>

using namespace std;

int dp(int start, int end);

int arr[11][2];


int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i][0]>>arr[i][1];
    cout<<dp(0, n-1)<<endl;               //从上到下
}

int dp(int start, int end)
{
    if(start==end)
        return 0;
    int min = INT_MAX;
    int a, b, c;
    for(int i = start; i < end; i++)
    {
        a = dp(start, i);
        b = dp(i+1, end);
        c = a + b + arr[start][0] * arr[i][1] * arr[end][1];
        //cout<<start<<' '<<end<<' '<<a<<' '<<b<<' '<<c<<endl;
        if(c < min)
            min = c;
    }
    //cout<<start<<' '<<end<<' '<<min<<endl;
    return min;
}

