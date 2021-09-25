#include <iostream>

using namespace std;

int n;
int stacks[10];
int ship1, ship2, ship3;

bool dp(int ship1, int ship2, int ship3, int depth);

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>stacks[i];
    cin>>ship1>>ship2>>ship3;
    if(dp(ship1, ship2, ship3, 0))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}

bool dp(int ship1, int ship2, int ship3, int depth)
{
    if(depth == n)
        return true;
    if(ship1<0||ship2<0||ship3<0)
        return false;
    if(dp(ship1 - stacks[depth], ship2, ship3, depth + 1)||
            dp(ship1, ship2-stacks[depth], ship3, depth + 1)||
            dp(ship1, ship2, ship3-stacks[depth], depth + 1))
        return true;
    return false;
}
