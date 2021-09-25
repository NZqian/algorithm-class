#include <iostream>
#include <memory.h>
using namespace std;
void show_color(int color[][51], int m, int n);
void show_grid(char grid[][51], int m, int n);
struct block{
    bool up, down, left, right;
    char C;
    block(char c)
    {
        C=c;
        if(c=='A')
        {
            up = true;
            right = false;
            down = false;
            left = true;
        }
        else if(c=='B')
        {
            up = true;
            right = true;
            down = false;
            left = false;
        }
        else if(c=='C')
        {
            up = false;
            right = false;
            down = true;
            left = true;
        }
        else if(c=='D')
        {
            up = false;
            right = true;
            down = true;
            left = false;
        }
        else if(c=='E')
        {
            up = true;
            right = false;
            down = true;
            left = false;
        }
        else if(c=='F')
        {
            up = false;
            right = true;
            down = false;
            left = true;
        }
        else if(c=='G')
        {
            up = true;
            right = true;
            down = false;
            left = true;
        }
        else if(c=='H')
        {
            up = true;
            right = false;
            down = true;
            left = true;
        }
        else if(c=='I')
        {
            up = false;
            right = true;
            down = true;
            left = true;
        }
        else if(c=='J')
        {
            up = true;
            right = true;
            down = true;
            left = false;
        }
        else if(c=='K')
        {
            up = true;
            right = true;
            down = true;
            left = true;
        }
    }
};
bool connected(block cur, block other, int side);
int main()
{
    block arr[11]={block('A'), block('B'), block('C'), block('D'), block('E'), block('F'), block('G'), block('H'), block('I'), block('J'), block('K')};
    int m, n;
    char grid[51][51];
    int color[51][51]={0};
    while(1)
    {
        cin>>m>>n;
        if(m==-1&&n==-1)
            return 0;
        int cur=0;
        memset(grid, '\0', sizeof(grid));
        memset(color, 0, sizeof(color));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>grid[i][j];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                bool flag=false;
                if((j>=1&&connected(arr[grid[i][j]-'A'],arr[grid[i][j-1]-'A'], 2))&&(i>=1&&connected(arr[grid[i][j]-'A'],arr[grid[i-1][j]-'A'], 1)))
                {
                    int minnum=min(color[i-1][j],color[i][j-1]);
                    if(color[i-1][j]!=color[i][j-1])
                        cur--;
                    color[i-1][j]=color[i][j-1]=color[i][j]=minnum;
                }
                else if((j>=1&&connected(arr[grid[i][j]-'A'],arr[grid[i][j-1]-'A'], 2)))
                {
                    color[i][j]=color[i][j-1];
                }
                else if((i>=1&&connected(arr[grid[i][j]-'A'],arr[grid[i-1][j]-'A'], 1)))
                {
                    color[i][j]=color[i-1][j];
                }
                else
                {
                    cur++;
                    //cout<<i<<' '<<j<<endl;
                    color[i][j]=cur;
                }
            }
        }
        //show_grid(grid, m, n);
        //show_color(color, m, n);
        cout<<cur<<endl;
    }
}
bool connected(block cur, block other, int side)
{
    if(side == 1)                               //side=1,cur在other下方
    {
        if(cur.up&&other.down)
            return true;
        //cout<<"failed up "<<other.C<<' '<<cur.C<<endl;
        return false;
    }
    else if(side == 2)                          //side=2,cur在other右方
    {
        if(cur.left&&other.right)
            return true;
        //cout<<"failed left "<<other.C<<' '<<cur.C<<endl;
        return false;
    }
    return false;
}
void show_color(int color[][51], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<color[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
void show_grid(char grid[][51], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
