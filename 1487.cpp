#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, max, cnt = 0;
    cin>>n>>max;
    vector<int> arr(n);
    for(int i = 0; i < n-1; i++)
        arr[i] = 0;
    arr[n-1] = 1;
    int pos = 0;
    while(1)
    {
        int cursum = 0, i = pos + 1;
        while(1)
        {
            i%=n;
            if(i == pos)
            {
                cursum += arr[i];
                break;
            }
            cursum += arr[i];
            i++;
        }
        //cout<<endl;
        //cout<<cursum<<endl;
        if(cursum <= max)
            arr[pos] = cursum;
        else
        {
            cout<<cnt + n - 1<<endl;
            cout<<arr[pos-1]<<endl;
            return 0;
        }
        pos ++;
        pos %= n;
        cnt ++;
    }
}
