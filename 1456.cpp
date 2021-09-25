#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ra(a), rb(b), rc(c);
    for(int i = 0; i < a; i++)
    {
        cin>>ra[i];
    }
    for(int i = 0; i < b; i++)
    {
        cin>>rb[i];
        if(m.count(rb[i]))
            m[rb[i]]++;
        else
            m[rb[i]] = 1;
    }
    for(int i = 0; i < c; i++)
    {
        cin>>rc[i];
        if(m.count(rc[i]))
            m[rc[i]]++;
        else
            m[rc[i]] = 1;
    }
    for(int i = 0; i < ra.size() ;)
    {
        if(m[ra[i]] >= 2)
            ra.erase(ra.begin() + i);
        else
            i++;
    }
    for(int i = 0; i < ra.size(); i++)
        cout<<ra[i]<<endl;
}
