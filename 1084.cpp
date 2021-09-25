#include <iostream>
#include <memory.h>

using namespace std;

int can_win[1001][1001];

int dp(int num, int can_choose)
{
    if(num == 1)
    {
        can_win[num][can_choose] = 0;
        return 0;
    }
    if(can_win[num][can_choose] >= 0)
        return can_win[num][can_choose]; 
    for(int i = 1; i <= can_choose&& i<=num; i++)
    {
        if(dp(num-i,2*i) == 0)
        {
            can_win[num][can_choose] = 1;
            return 1;
        }
    }
    can_win[num][can_choose] = 0;
    return 0;
}

int main()
{
    memset(can_win, -1, sizeof(can_win));
    int n;
    while(cin>>n&&n)
        cout<<dp(n, 1)<<endl;
}
