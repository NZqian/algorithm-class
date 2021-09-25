#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point{
    int x, y;
    point(){}
    point(int a, int b)
    {
        x=a, y=b;
    }
    void padd(point b)
    {
        x+=b.x;
        y+=b.y;
    }
    void pminus(point b)
    {
        x-=b.x;
        y-=b.y;
    }
};
int main()
{
    int m, n;
    point start, end;
    cin>>m>>n;
    cin>>start.x>>start.y>>end.x>>end.y;
    vector<vector<int> > puzzle(m, vector<int>(n));
    point near[4]={point(-1,0), point(1, 0), point(0, -1), point(0, 1)};
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>puzzle[i][j];
    queue<point> q;  
    if(start.x>=0&&start.x<m&&start.y>=0&&start.y<n)
        q.push(start);
    while(!q.empty())
    {
        point cur=q.front();
        puzzle[cur.x][cur.y] = 2;
        for(int i = 0; i < 4; i++)
        {
            cur.padd(near[i]);
            if(cur.x>=0&&cur.x<m&&cur.y>=0&&cur.y<n&&puzzle[cur.x][cur.y]==0)
            {
                puzzle[cur.x][cur.y] = 2;
                q.push(cur);
            }
            cur.pminus(near[i]);
        }
        q.pop();
    }
    if(puzzle[end.x][end.y]==2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
