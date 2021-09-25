#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    stack<int> s;
    cin>>str;
    for(int i = 0; i < str.length(); i++)
    {
        int tmp = -1;
        if(!s.empty())
            tmp = s.top();
        if(str[i] == '(' || str[i] == ')')
            s.push(1);
        else if(str[i] == '[' || str[i] == ']')
            s.push(2);
        else if(str[i] == '{' || str[i] == '}')
            s.push(3);
        if(s.top() == tmp)
        {
            s.pop();
            s.pop();
        }
    }
    if(s.empty())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
