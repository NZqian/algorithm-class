#include <iostream>

using namespace std;

int n;
int board[21];
int ans = 0;

bool is_possible(int x, int y);
void search(int x);

int main()
{
    cin>>n;
    search(1);
    cout<<ans<<endl;
}

void search(int x)
{
    if(x == n + 1)
    {
        ans++;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(board[i] != 0)
            continue;
        if(is_possible(x, i))
        {
            board[i] = x;
            search(x + 1);
            board[i] = 0;
        }
    }
}

bool is_possible(int x, int y)
{
    for(int i = 1; i <= n; i++)
    {
        if(board[i] == 0 || board[i] == x)
            continue;
        if(y - x == i - board[i])
            return false;
        if(y + x == i + board[i])
            return false;
    }
    return true;
}
