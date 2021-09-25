#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int bfs(vector<vector<char> > cube);
bool isvalid(vector<vector<char> > cube);
void rotate(vector<vector<char> >& cube, int method);
void show_cube(vector<vector<char> >& cube);

int main()
{
    vector<vector<char> > cube(12,vector<char>(2));
    for(int i=0; i<12; i++)
        for(int j=0; j<2; j++)
            cin>>cube[i][j];
    if(isvalid(cube))
    {
        cout<<0<<endl;
        return 0;
    }
    //rotate(cube, 6);
    //show_cube(cube);
    cout<<bfs(cube)<<endl;
}

int bfs(vector<vector<char> > cube)
{
    map<vector<vector<char> >,int> visited;
    queue<vector<vector<char> > > q;
    q.push(cube);
    visited[cube]=1;
    int cur = 1, next = 0, ans = 0;
    while(!q.empty())
    {
        while(cur)
        {
            vector<vector<char> > cur_cube = q.front();
            vector<vector<char> > ori_cube = cur_cube;
            q.pop();
            cur--;
            for(int i = 1; i<=6; i++)
            {
                cur_cube = ori_cube;
                rotate(cur_cube, i);
                if(isvalid(cur_cube))
                {
                    ans++;
                    return ans;
                }
                if(!visited.count(cur_cube))
                {
                    //show_cube(cur_cube);
                    q.push(cur_cube);
                    visited[cur_cube]=1;
                    next++;
                }
            }
        }
        cur = next;
        next = 0;
        ans++;
    }
    return -1;
}

void show_cube(vector<vector<char> >& cube)
{
    cout<<endl;
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<cube[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isvalid(vector<vector<char> > cube)
{
    for(int i=0; i<12; i+=2)
    {
        bool flag=true;
        for(int j=i; j<i+2; j++)
        {
            for(int k=0; k<2; k++)
                if(cube[j][k]=='1')
                {
                    flag=false;
                    break;
                }
        }
        if(flag)
            return true;
    }
    return false;
}

void rotate(vector<vector<char> >& cube, int method)
{
    if(method==1)
    {
        //底面转
        int tmp     = cube[2][0];
        cube[2][0]  = cube[3][0];
        cube[3][0]  = cube[3][1];
        cube[3][1]  = cube[2][1];
        cube[2][1]  = tmp;
        //侧面转
        int tmp1 = cube[9][0], tmp2 = cube[9][1];
        cube[9][0] = cube[7][1], cube[9][1] = cube[7][0];
        cube[7][1] = cube[11][1], cube[7][0] = cube[11][0];
        cube[11][1] = cube[5][0], cube[11][0] = cube[5][1];
        cube[5][0] = tmp1, cube[5][1] = tmp2;
     }
    else if(method==2)
    {

        //底面转
        int tmp     = cube[2][0];
        cube[2][0]  = cube[2][1];
        cube[2][1]  = cube[3][1];
        cube[3][1]  = cube[3][0];
        cube[3][0]  = tmp;
        //侧面转
        int tmp1 = cube[9][0], tmp2 = cube[9][1];
        cube[9][0] = cube[5][0], cube[9][1] = cube[5][1];
        cube[5][0] = cube[11][1], cube[5][1] = cube[11][0];
        cube[11][0] = cube[7][0], cube[11][1] = cube[7][1];
        cube[7][0] = tmp2, cube[7][1] = tmp1;
    }
    else if(method==3)      //right
    {
        int tmp     = cube[6][0];
        cube[6][0]  = cube[6][1];
        cube[6][1]  = cube[7][1];
        cube[7][1]  = cube[7][0];
        cube[7][0]  = tmp;

        int tmp1 = cube[0][1], tmp2 = cube[1][1];
        cube[0][1] = cube[8][1], cube[1][1] = cube[9][1];
        cube[8][1] = cube[3][1], cube[9][1] = cube[2][1];
        cube[3][1] = cube[11][1], cube[2][1] = cube[10][1];
        cube[11][1] = tmp1, cube[10][1] = tmp2;
    }
    else if(method==4)
    {
        int tmp     = cube[6][0];
        cube[6][0]  = cube[7][0];
        cube[7][0]  = cube[7][1];
        cube[7][1]  = cube[6][1];
        cube[6][1]  = tmp;

        int tmp1 = cube[0][1], tmp2 = cube[1][1];
        cube[0][1] = cube[11][1], cube[1][1] = cube[10][1];
        cube[11][1] = cube[3][1], cube[10][1] = cube[2][1];
        cube[3][1] = cube[8][1], cube[2][1] = cube[9][1];
        cube[8][1] = tmp1, cube[9][1] = tmp2;
    }
    else if(method==5)
    {
        int tmp    = cube[8][0];
        cube[8][0] = cube[9][0];
        cube[9][0] = cube[9][1];
        cube[9][1] = cube[8][1];
        cube[8][1] = tmp;

        int tmp1 = cube[1][0], tmp2 = cube[1][1];
        cube[1][0] = cube[5][1], cube[1][1] = cube[4][1];
        cube[5][1] = cube[3][1], cube[4][1] = cube[3][0];
        cube[3][1] = cube[6][1], cube[3][0] = cube[7][1];
        cube[6][1] = tmp1, cube[7][1] = tmp2;
    }
    else if(method==6)
    {
        int tmp    = cube[8][0];
        cube[8][0] = cube[8][1];
        cube[8][1] = cube[9][1];
        cube[9][1] = cube[9][0];
        cube[9][0] = tmp;

        int tmp1 = cube[1][0], tmp2 = cube[1][1];
        cube[1][0] = cube[6][1], cube[1][1] = cube[7][1];
        cube[6][1] = cube[3][1], cube[7][1] = cube[3][0];
        cube[3][1] = cube[5][1], cube[3][0] = cube[4][1];
        cube[5][1] = tmp1, cube[4][1] = tmp2;
    }
}