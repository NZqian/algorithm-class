#include <iostream>

using namespace std;

int link[500][500];
int t[500];
int d[500];

int main()
{
    int n, cnt = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> link[i][j];
    t[0] = 1;
    for(int i = 1; i < n; i++)
        d[i] = link[0][i];
    while(cnt < n - 1)
    {
        int min = 0x3f3f3f, minpoint;
        for(int i = 1; i < n; i++)
        {
            if(t[i] == 0 && d[i] < min)
            {
                min = d[i];
                minpoint = i;
            }
        }
        t[minpoint] = 1;
        ans += d[minpoint];
        cnt ++;
        for(int i = 1; i < n; i++)
        {
            if(t[i])
                continue;
            if(link[minpoint][i] < d[i])
                d[i] = link[minpoint][i];
        }
    }
    cout<<ans<<endl;
}
