#include <iostream>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int stones[100], all = 0, stones_add[100];
int n;

int dp(map<vector<int>, int>& visited, int start, int end)      //包括头尾
{
    if(start<0)
        start += n;
    if(end<0)
        end += n;
    start%=n;
    end%=n;

    if(start == end)
        return 0;

    vector<int> curdp;
    curdp.push_back(start);
    curdp.push_back(end);

    if(visited.count(curdp))
        return visited[curdp];
    int min = INT_MAX;
    int sum = 0;
    if(end < start)
        end += n;
    for(int i = start; i <= end; i++)
    {
        int pos = i%n;
        sum += stones[pos];
    }
    for(int i = start; i < end; i++)
    {
        int pos = i % n;
        int a = dp(visited, start, pos);
        int b = dp(visited, pos + 1, end);
        int cur = a + b + sum;
        if(cur < min)
            min = cur;
        //if(start == 2 && end == 4)
        //{
        //    cout<<"in "<<a<<' '<<b<<' '<<cur<<endl;
        //}
    }
    visited[curdp] = min;
    return min;
}

int main()
{
    int cur;
    while(cin>>n)
    {
        if(n == 0)
            return 0;
        all = 0;
        map<vector<int>, int> visited;
        for(int i = 0; i < n; i++)
        {
            cin>>cur;
            if(!cur)
                break;
            stones[i] = cur;
            all += cur;
            if(i > 0)
                stones_add[i] = stones_add[i-1] +cur;
            else
                stones_add[i] = cur;
        }
        if(n == 1)
        {
            cout<<0<<endl;
            continue;
        }
        int min = INT_MAX;
        for(int j = 0; j < n-1; j++)
        {
            for(int k = j; k < n; k++)
            {
                //cout<<j<<' '<<k<<' '<<k+1<<' '<<j-1<<endl;
                int a = dp(visited, j, k);
                int b = dp(visited, k+1, j-1);
                int cur_ans = a + b + all;
                //cout<<j<<' '<<k<<' '<<a<<' '<<b<<' '<<cur_ans<<endl;
                if(cur_ans < min)
                    min = cur_ans;
            }
        }
        cout<<min<<endl;
    }
}
