#include <iostream>
#include <queue>
#include <map>

using namespace std;
int rotate(int cur, int method);
bool bfs(queue<int> q, map<int,int> m);

int main()
{
    int tmp;
    int curnum;
    while(cin >> curnum)
    {
        queue<int> q;
        map<int, int> m;
        for(int i=0; i<5; i++)
        {
            cin>>tmp;
            curnum*=10;
            curnum+=tmp;
        }
        q.push(curnum);
        m[curnum] = 1;
        //cout<<rotate(123456,1)<<endl<<rotate(123456,2)<<endl;
        if(bfs(q, m))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}

int rotate(int cur, int method)
{
    int chart[2][3];
    int tmp = cur;
    for(int i=1; i>=0; i--)
    {
        for(int j=2; j>=0; j--)
        {
            chart[i][j]=tmp%10;
            tmp/=10;
        }
    }
    //for(int i=0; i<2; i++)
    if(method == 1)
    {
        tmp=chart[0][0];
        chart[0][0]=chart[1][0];
        chart[1][0]=chart[1][1];
        chart[1][1]=chart[0][1];
        chart[0][1]=tmp;
    }
    else if(method == 2)
    {
        tmp=chart[0][1];
        chart[0][1]=chart[1][1];
        chart[1][1]=chart[1][2];
        chart[1][2]=chart[0][2];
        chart[0][2]=tmp;
    }
    tmp=0;
    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)
        {
            tmp*=10;
            tmp+=chart[i][j];
        }
    return tmp;
}
bool bfs(queue<int> q, map<int,int> m)
{
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=1; i<=2; i++)
        {
            int tmp = rotate(cur, i);
            if(tmp == 123456)
                return true;
            else if(m[tmp]!=1)
            {
                q.push(tmp);
                m[tmp]=1;
            }
        }
    }
    return false;
}
