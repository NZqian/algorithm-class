#include <iostream>
#include <iomanip>

#define inf 0x3f3f3f

using namespace std;

int n, link[52];
double len, gas_size, price_ori, mile_gas;
double dp[52], dis[52], price[52];
int main()
{
    cin >> len >> gas_size >> mile_gas >> price_ori >> n;
    for(int i = 1; i <= n; i++)
        cin >> dis[i] >> price[i];
    int i = n, j;
    while(len-dis[i] <= gas_size * mile_gas)
        dp[i--] = 0;
    dis[0] = 0;
    dis[n + 1] = len;
    for(;i >= 0; i--)
    {
        dp[i] = inf;
        int minpos;
        double tmp;
        for(j = i + 1; j <=n; j++)
        {
            if(gas_size * mile_gas < dis[j] - dis[i])
                break;
            if((dis[j]-dis[i])/mile_gas < gas_size / 2
               && (dis[j+1]-dis[i])/mile_gas <= gas_size)
                continue;
            tmp = 2;
            tmp += (dis[j] - dis[i]) / mile_gas * price[j];
            tmp += dp[j];
            if(tmp < dp[i])
            {
                dp[i] = tmp;
                minpos = j;
            }
        }
        link[i] = minpos;
    }
    cout <<fixed<<setprecision(2)<< dp[0] + price_ori <<' ';
    //for(int i = 0; i <=n; i++)
    //    cout<<link[i]<<endl;
    int cnt = 0, cur = 0;
    while(1)
    {
        cur = link[cur];
        if(cur == 0)
            break;
        cnt ++;
    }
    cout<<cnt<<endl;
    cur = 0;
    while(1)
    {
        cur = link[cur];
        if(cur == 0)
            break;
        cout<<cur<<' ';
    }
    cout<<endl;
}

