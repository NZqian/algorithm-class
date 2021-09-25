#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n, aim;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> aim;
    sort(arr.begin(), arr.end());
    int ans = arr[aim - 1];
    cout << ans << endl;
}