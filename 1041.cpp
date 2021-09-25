#include <iostream>
#include <string>

using namespace std;
string a, b;
int dp(int x, int y);

int main()
{
    cin>>a>>b;
    cout<<dp(a.size()-1, b.size()-1)<<endl;
}

int dp(int x, int y)
{
    if(x < 0 || y < 0)
        return 0;
    else
    {
        if(a[x] == b[y])
        {
            return dp(x-1, y-1)+1;
        }
        else
        {
            return max(dp(x-1, y), dp(x, y-1));
        }
    }
}
