#include <iostream>
#include <queue>
#include <memory.h>

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
        x += b.x, y += b.y;
    }
    void pminus(point b)
    {
        x -= b.x, y -= b.y;
    }
};
int main()
{
    point in, out;
    point near[4]={point(-1, 0), point(1, 0), point(0, 1), point(0, -1)};
    cin>>in.x>>in.y>>out.x>>out.y;
    if(in.x==out.x&&in.y==out.y)
    {
        cout<<0<<endl;
        return 0;
    }
    char puzzle[13][13];
    for(int i=1; i<=12; i++)
        for(int j = 1; j <= 12; j++)
            cin>>puzzle[i][j];
    bool visited[13][13]; 
    memset(visited, false, sizeof(visited));
    queue<point> q;
    q.push(in);
    int cur=1, next=0, ans=0;
    while(1)
    {
        while(cur--)
        {
            point now = q.front();
            visited[now.x][now.y]=true;
            //cout<<now.x<<' '<<now.y<<endl;
            for(int i = 0; i < 4; i++)
            {
                now.padd(near[i]);
                if(now.x>=1&&now.x<=12&&now.y>=1&&now.y<=12&&puzzle[now.x][now.y]=='.'&&!visited[now.x][now.y])
                {
                    if(now.x==out.x&&now.y==out.y)
                    {
                        cout<<ans+1<<endl;
                        return 0;
                    }
                    q.push(now);
                    visited[now.x][now.y]=true;
                    next++;
                }
                now.pminus(near[i]);
            }
            q.pop();
        }
        cur=next;
        next=0;
        ans++;
        //cout<<endl;
    }
}

