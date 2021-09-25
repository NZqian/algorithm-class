#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int main()
{
    int n, c;
    int arr[101] = {0}, weight[11] = {0}, value[11] = {0};
    while(cin>>n>>c)
    {
        if(!n&&!c)
            return 0;
        memset(arr, 0, sizeof(arr));
        memset(weight, 0, sizeof(weight));
        memset(value, 0, sizeof(value));
        for (int i = 1; i <= n; i++)
            cin >> weight[i];
        for (int i = 1; i <= n; i++)
            cin >> value[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = c; j >= weight[i]; j--)
            {
                arr[j] = max(arr[j], arr[j - weight[i]] + value[i]);
            }
        }
        cout << arr[c] << endl;
    }
}
