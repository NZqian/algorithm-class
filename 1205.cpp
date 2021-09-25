#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    //int events[1001][2];
    cin>>n;
    vector<vector<int> > events;
    for(int i = 0; i < n; i++)
    {
        vector<int> tmp(2);
        cin>>tmp[1]>>tmp[0];
        events.push_back(tmp);
    }
    sort(events.begin(), events.end());

    for(int i = 0; i < events.size(); i++)
        swap(events[i][0], events[i][1]);

    //for(int i = 0; i < events.size(); i++)
    //    cout<<events[i][0]<<' '<<events[i][1]<<endl;
    int end = events[0][1];
    int ans = 1;
    for(int i = 1; i < events.size(); i++)
    {
        int start = events[i][0];
        if(start>=end)
        {
            end = events[i][1];
            ans ++;
            continue;
        }
    }
    cout<<ans<<endl;
}

