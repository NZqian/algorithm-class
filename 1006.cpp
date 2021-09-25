#include <iostream>
using namespace std;

void search(int n, int size, char grid[][5], int cur, int& max);
bool ispossible(char grid[][5], int x, int y);
void show(char grid[][5], int size);
int main()
{
    int size;
    char grid[5][5];
    while(1)
    {
        cin >> size;
        if(!size)
            return 0;
        int max = 0;
        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= size; j++)
                cin>>grid[i][j];
        search(1, size, grid, 0, max);
        cout<<max<<endl;
    }
}
void search(int n, int size, char grid[][5], int cur, int& max)
{
    if(n==size*size+1)
    {
        if(cur > max)
            max = cur;
        //if(cur==2)
        //    show(grid, size);
        return ;
    }
    int x, y;
    x = n % size == 0 ? n / size : n / size + 1;
    y = n - (n / size) * size;
    if(y==0)
        y=size;
    //cout<<n<<' '<<x<<' '<<y<<endl;
    if(grid[x][y]=='X')
    {
        search(n+1, size, grid, cur, max);
        return ;
    }
    search(n+1, size, grid, cur, max);
    grid[x][y]='A';
    cur++;
    if(ispossible(grid, x,y))
        search(n+1, size, grid, cur, max);
    grid[x][y]='.';
}

bool ispossible(char grid[][5], int x, int y)
{
    for(int i = x-1; i>=1; i--)
    {
        if(grid[i][y]=='X')
            break;
        if(grid[i][y]=='A')
            return false;
    }
    for(int i = y-1; i>=1; i--)
    {
        if(grid[x][i]=='X')
            break;
        if(grid[x][i]=='A')
            return false;
    }
    return true;
}
void show(char grid[][5], int size)
{
    for(int i=1; i<=size; i++)
    {
        for(int j=1; j<=size; j++)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}
