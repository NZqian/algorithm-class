#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
struct point{
    int x, y;
    point(){}
    point(int a, int b)
    {
        x = a, y = b;
    }
    void padd(point b)
    {
        x += b.x;
        y += b.y;
    }
    void pminus(point b)
    {
        x -= b.x;
        y -= b.y;
    }
};
int main()
{
    int n;
    cin>>n;
    point start, end;
    point near[8]={point(-2, -1), point(-1, -2), point(1, -2), point(2, -1), point(2, 1), point(1, 2), point(-1, 2), point(-2, 1)};
    bool visited[201][201];
    memset(visited, false, sizeof(visited));
    while(n--)
    {
        cin>>start.x>>start.y>>end.x>>end.y;
        memset(visited, false, sizeof(visited));
        if(start.x==end.x&&start.y==end.y)
        {
            cout<<0<<endl;
            continue;
        }
        queue<point> q;
        q.push(start);
        int cur=1, next=0, ans=0;
        while(1)
        {
            while(cur--)
            {
                point now=q.front();
                //cout<<now.x<<' '<<now.y<<endl;
                visited[now.x][now.y]=true;
                for(int i=0; i<8; i++)
                {
                    now.padd(near[i]);
                    if(now.x>=1&&now.x<=200&&now.y>=1&&now.y<=200&&!visited[now.x][now.y])
                    {
                        if(now.x==end.x&&now.y==end.y)
                        {
                            cout<<ans+1<<endl;
                            goto here;
                        }
                        visited[now.x][now.y]=true;
                        q.push(now);
                        next++;
                    }
                    now.pminus(near[i]);
                }
                q.pop();
            }
            cur=next;
            next=0;
            ans++;
        }
here:
        continue;
    }
}
