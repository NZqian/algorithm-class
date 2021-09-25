#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int dp(map<vector<int>, int>& visited, vector<int>& speed_qi, vector<int>& speed_tian, int start_qi, int end_qi, int start_tian, int end_tian)
{
    if(start_qi>end_qi)
        return 0;
    vector<int> cur;
    cur.push_back(start_qi);
    cur.push_back(end_qi);
    cur.push_back(start_tian);
    cur.push_back(end_tian);
    if(visited[cur])
        return visited[cur];
    int first_win, last_win;
    if(speed_tian[start_tian]>speed_qi[start_qi])
        first_win = 1;
    else if(speed_tian[start_tian]==speed_qi[start_qi])
        first_win = 0;
    else
        first_win = -1;

    if(speed_tian[end_tian]>speed_qi[start_qi])
        last_win = 1;
    else if(speed_tian[end_tian]==speed_qi[start_qi])
        last_win = 0;
    else
        last_win = -1;
    int first = dp(visited, speed_qi, speed_tian, start_qi + 1, end_qi, start_tian + 1, end_tian) + first_win;
    int last = dp(visited, speed_qi, speed_tian, start_qi + 1, end_qi, start_tian, end_tian - 1) + last_win;
    int cur_ans = max(first, last);
    visited[cur] = cur_ans;
    return max(first, last);
}

int main()
{
    int n;
    vector<int> speed_qi(101), speed_tian(101);
    while(cin>>n)
    {
        if(!n)
            return 0;
        //memset(speed_qi, 0, size)
        speed_qi.resize(n);
        speed_tian.resize(n);

        map<vector<int>, int> visited;

        for(int i = 0; i < n; i++)
            cin>>speed_tian[i];
        for(int i = 0; i < n; i++)
            cin>>speed_qi[i];
        sort(speed_qi.rbegin(), speed_qi.rend());
        sort(speed_tian.rbegin(), speed_tian.rend());
        cout<<dp(visited, speed_qi, speed_tian, 0, n-1, 0, n-1)<<endl;
    }
}
