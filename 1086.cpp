#include <iostream>
#include <vector>
#include <memory.h>
#include <map>

using namespace std;

int visited[10001];
double a;
int all;

int dp(int left)
{
    if(visited[left]>=0)
        return visited[left];

    int min_pick = all - left;
    if(left < min_pick)
    {
        visited[left] = 0;
        return 0;
    }
    for(int i = min_pick; i <= 3 * min_pick; i++)
    {
        if(!dp(left - i))
        {
            visited[left] = 1;
            return 1;
        }
    }
    visited[left] = 0;
    return 0;
}

int main()
{
    while(cin>>a&&a>0)
    {
        memset(visited, -1, sizeof(visited));
        all = a * 10;
        if(all < 10)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<1-dp(all-10)<<endl;
    }
}

