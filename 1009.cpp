#include <iostream>
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
	point start, end;
	point near[4]={point(-1,0), point(1,0), point(0,-1), point(0,1)};
	char puzzle[20][20];
	int n;
	cin>>n;
	while(n--)
	{
		cin>>start.x>>start.y>>end.x>>end.y;
		for(int i=0; i<20; i++)
		{
			for(int j=0; j<20; j++)
			{
				cin>>puzzle[i][j];
			}
		}
		queue<point> q;
		if(puzzle[start.x][start.y]=='X')
		{
			cout<<"No"<<endl;
			continue;
		}
		q.push(start);
		while(!q.empty())
		{
			point cur=q.front();
			puzzle[cur.x][cur.y]='A';
			for(int i=0; i<4; i++)
			{
				cur.padd(near[i]);
				if(cur.x>=0&&cur.x<20&&cur.y>=0&&cur.y<20&&puzzle[cur.x][cur.y]=='.')
				{
					puzzle[cur.x][cur.y]='A';
					q.push(cur);
				}
				cur.pminus(near[i]);
			}
			q.pop();
		}
		if(puzzle[end.x][end.y]=='A')
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
