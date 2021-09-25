#include <iostream>
#include <memory.h>
#include <map>
#include <queue>

using namespace std;
int bfs(queue<int> q, map<int,int> visited, int aim);
int move(int num, int side);

int main()
{
   int tmp, num=0;
   int aim = 123456780;
   for(int i=0; i<9; i++)
   {
       cin>>tmp;
       num*=10;
       num+=tmp;
   }
   //cin>>num;
   queue<int> q;
   map<int,int> visited;
   visited[num]=1;
   q.push(num);
   //cout<<move(123406758,1)<<move(123406758,2)<<move(123406758,3)<<move(123406758,4)<<endl;
   if(num==aim)
       cout<<0<<endl;
   else
       cout<<bfs(q,visited, aim)<<endl;
}

int bfs(queue<int> q, map<int,int> visited, int aim)
{
    int cur = 1, next = 0, ans = 0, curnum;
    while(!q.empty())
    {
        while(cur)
        {
            curnum = q.front();
            cur--;
            q.pop();
            for(int i=1; i<=4; i++)
            {
                int tmp = move(curnum,i);
                if(tmp!=-1&&visited[tmp]!=1)
                {
                    //cout<<tmp<<endl;
                    if(tmp == aim)
                    {
                        ans++;
                        return ans;
                    }
                    q.push(tmp);
                    next++;
                    visited[tmp]=1;
                }
            }
        }
        ans ++;
        cur = next;
        next = 0;
    }
    return -1;
}


int move(int num, int side)
{
    int tmp = num;
    int chart[3][3];
    memset(chart, 0, sizeof(chart));
    int x, y;
    for(int i=2; i>=0; i--)
    {
        for(int j=2; j>=0; j--)
        {
            chart[i][j] = tmp % 10;
            if(tmp%10==0)
            {
                x=i;
                y=j;
            }
            tmp /= 10;
        }
    }
    if(side==1&&x!=0)
    {
        chart[x][y] = chart[x-1][y];
        chart[x-1][y] = 0;
    }
    else if(side == 2&&y!=2)
    {
        chart[x][y] = chart[x][y+1];
        chart[x][y+1] = 0;
    }
    else if(side == 3&&x!=2)
    {
        chart[x][y] = chart[x+1][y];
        chart[x+1][y] = 0;
    }
    else if(side == 4&&y!=0)
    {
        chart[x][y] = chart[x][y-1];
        chart[x][y-1] = 0;
    }
    else
        return -1;
    tmp = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            tmp *= 10;
            tmp += chart[i][j];
        }
    }
    return tmp;
}

