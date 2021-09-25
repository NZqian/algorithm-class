#include <iostream>
#include <vector>

using namespace std;

class mystack
{
public:
    int push(int n)
    {
        thisstack.push_back(n);
        return 0;
    }
    int pop()
    {
        if(thisstack.empty())
            return -1;
        thisstack.pop_back();
        return 0;
    }
    bool empty()
    {
        if(!thisstack.size())
            return true;
        return false;
    }
    int top()
    {
        if(thisstack.empty())
            return -1;
        return thisstack[thisstack.size()-1];
    }
private:
    vector<int> thisstack;
};
int main()
{

    int n, m, pos = 0;
    int arr[100];
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    mystack s;
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        int tmp, curnum;
        cin>>tmp;
        if(tmp == 0)
        {
            curnum = s.top();
            cout<<curnum<<endl;
            s.pop();
        }
        else if(tmp == 1)
        {
            s.push(arr[pos]);
            pos++;
        }
    }
}
