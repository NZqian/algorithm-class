#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int main()
{
    int m, n, cur, next, ans = 0;
    cin >> m >> n;
    queue<int> q;
    q.push(m);
    cur=1, next=0;
    bool visited[100000];
    memset(visited, false, sizeof(visited));
    visited[m]=true;
    while(1)
    {
        while(cur--)
        {
            int cnt=0;
            int num = q.front();
            q.pop();
            if(num+1==n||num*2==n||num*num==n)
            {
                cout << ans+1 << endl;
                return 0;
            }
            if(num+1<n&&!visited[num+1])
            {
                visited[num+1]=true;
                q.push(num+1);
                cnt++;
            }
            if(num*2<n&&!visited[num*2]&&num*2!=num+1)
            {
                visited[num*2]=true;
                q.push(num*2);
                cnt++;
            }
            if(num*num<n&&!visited[num*num]&&num*num!=num+1&&num*num!=num*2)
            {
                visited[num*num]=true;
                q.push(num*num);
                cnt++;
            }
            next+=cnt;
        }
        cur=next;
        next=0;
        ans++;
    }
}
