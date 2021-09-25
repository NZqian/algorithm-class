#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int bfs(queue<string> q, map<string, int> visited, string in, string out, vector<string> A, vector<string> B);
void dfs(map<string, int> visited, string curstr, vector<string> A, vector<string> B, string in, string out, int step);

int minstep = INT_MAX;
int main()
{
    string in, out;
    string test = "abcdef", a = "abc", b = "bc", c = "df";
    //cout<<test.find(a)<<endl<<test.find(b)<<endl<<test.find(c)<<endl;
    cin>>in>>out;
    string A1, B1;
    vector<string> A, B;

    while(cin>>A1>>B1)
    {
        A.push_back(A1);
        B.push_back(B1);
    }
    
    queue<string> q;
    map<string,int> visited;
    if(in==out)
    {
        cout<<1<<endl;
        return 0;
    }
    q.push(in);
    visited[in]=1;
    int ans = bfs(q,visited,in,out,A,B);
    if(ans == -1)
        cout<<"NO ANSWER!"<<endl;
    else
        cout<<ans<<endl;
}

void dfs(map<string, int> visited, string curstr, vector<string> A, vector<string> B, string in, string out, int step)
{
    if(step==minstep)
        return;
    if(curstr==out)
    {
        if(step<minstep)
            minstep=step;
    }
    for(int i = 0; i<curstr.size(); i++)
    {
        for(int j = 0; j<A.size(); j++)
        {
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            string tmp = curstr;
            int pos = curstr.find(A[j],i); 
            if(pos>=0&&pos<20)
            {
                //cout<<pos<<endl;
                tmp.replace(pos, A[j].length(), B[j]);
                //cout<<"cur: "<<tmp<<endl;
                
               if(visited[tmp]!=1)
               {
                    visited[tmp]=1;
                    dfs(visited, tmp, A, B, in, out, step+1);
               }

            }
        }
    }
}
int bfs(queue<string> q, map<string, int> visited, string in, string out, vector<string> A, vector<string> B)
{
    int cur = 1, next = 0, ans = 0;
    string curstr;
    while(!q.empty())
    {
        while(cur)
        {
            curstr = q.front();
            //cout<<"ori: "<<curstr<<endl;
            q.pop();
            cur--;
            for(int i = 0; i<curstr.size(); i++)
            {
                for(int j = 0; j<A.size(); j++)
                {
                    //cout<<"i:"<<i<<" j:"<<j<<endl;
                    string tmp = curstr;
                    int pos = curstr.find(A[j],i); 
                    if(pos>=0&&pos<20)
                    {
                        //cout<<pos<<endl;
                        tmp.replace(pos, A[j].length(), B[j]);
                        //cout<<"cur: "<<tmp<<endl;
                        if(tmp==out)
                        {
                            ans++;
                            return ans;
                        }
                        if(visited[tmp]!=1)
                        {
                            q.push(tmp);
                            visited[tmp]=1;
                            next++;
                        }
                    }
                }
            }
        }
        cur = next;
        next = 0;
        ans ++;
        if(ans == 10)
            return -1;
    }
    return -1;
}

