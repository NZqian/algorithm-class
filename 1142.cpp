#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <memory.h>

using namespace std;
bool judge(int x, bool visited[]);
int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        if(!m && !n)
            break;
        if(m>n)
        {
            int tmp = m;
            m = n;
            n = tmp;
        }
        //cout<<m<<' '<<n<<endl;
        bool visited[101]={false};
        bool flag1=judge(m,visited);
       //memset(visited,false,sizeof(visited));
        bool flag2=judge(n,visited);
        if(flag1&&flag2)
            cout<<n<<endl;
        else if(flag1&&!flag2)
            cout<<m<<endl;
        else
            cout<<"error"<<endl;
    }

}
bool judge(int x, bool visited[])
{
    for(int i=1; i<=100&&i<=x; i++)
    {
        //cout<<i<<' '<<x/i<<' '<<x%i<<endl;
        if(i==x)
        {
            visited[i]=true;
            //cout<<"return true1"<<endl;
            return true;
        }
        if(x/i<=100&&x%i==0&&visited[i]==false&&visited[x/i]==false)
        {
            visited[i]=true;
            visited[x/i]=true;
            //cout<<"return true2"<<endl;
            return true;
        }
    }
    //cout<<"return false"<<endl;
    return false;
}

