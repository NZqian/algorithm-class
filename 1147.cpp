#include <iostream>
#include <memory.h>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct point{
    int x, y;
    point(){}
    point(int a, int b)
    {
        x = a, y = b;
    }
    void padd(point b)
    {
        x += b.x;
        y += b.y;
    }
    void pminus(point b)
    {
        x -= b.x;
        y -= b.y;
    }
};

class node{
public:
    point man, mu;
};

int puzzle[11][11];

bool bfs(node& ori);
void init(node& ori);
void mummy_move(node& tmp);

int main()
{
    node ori;
    init(ori);
    //cout<<endl;
    //for(int i = 0; i<11; i++)
    //{
    //    for(int j = 0; j < 11; j++)
    //        cout<<puzzle[i][j]<<"    ";
    //    cout<<endl;
    //}
    //cout<<ori.man.x<<' '<<ori.man.y<<endl;
    //cout<<ori.mu.x<<' '<<ori.mu.y<<endl<<endl;
    if(bfs(ori))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

bool bfs(node& ori)
{
    if(ori.man.x==ori.mu.x&&ori.man.y==ori.mu.y)
        return false;
    else if(puzzle[ori.man.x][ori.man.y]==1)
        return true;

    queue<node> q;
    map<vector<int>, int> visited;

    q.push(ori);
    vector<int> tmp(4);
    tmp[0] = ori.man.x;
    tmp[1] = ori.man.y;
    tmp[2] = ori.mu.x;
    tmp[3] = ori.mu.y;
    
    visited[tmp]=1;
    //visited[ori]=1;
    int cur = 1, next = 0;

    point near[4] = {point(-1, 0), point(1, 0), point(0, -1), point(0, 1)};
    while(!q.empty())
    {
        while(cur)
        {
            node cur_node = q.front();
            //cout<<"cur:"<<cur_node.man.x<<' '<<cur_node.man.y<<' '<<
            //    cur_node.mu.x<<' '<<cur_node.mu.y<<endl;
            node tmp_node;
            q.pop();
            cur--;
            for(int i = 0; i < 4; i++)
            {
                tmp_node = cur_node;
                tmp_node.man.padd(near[i]);
                if(puzzle[tmp_node.man.x][tmp_node.man.y]==-1)
                    continue;
                else
                    tmp_node.man.padd(near[i]);
                if(puzzle[tmp_node.man.x][tmp_node.man.y]==1)
                    return true;
                mummy_move(tmp_node);
                //cout<<"tmp:"<<tmp_node.man.x<<' '<<tmp_node.man.y<<' '<<
                //    tmp_node.mu.x<<' '<<tmp_node.mu.y<<endl;
                tmp[0] = tmp_node.man.x;
                tmp[1] = tmp_node.man.y;
                tmp[2] = tmp_node.mu.x;
                tmp[3] = tmp_node.mu.y;
                //cout<<' '<<visited[tmp]<<endl;
                if(tmp_node.man.x>=0&&tmp_node.man.x<=10&&
                   tmp_node.man.y>=0&&tmp_node.man.y<=10&&(
                   tmp_node.man.x!=tmp_node.mu.x||
                   tmp_node.man.y!=tmp_node.mu.y)&&
                   visited[tmp]!=1)
                {
                    visited[tmp] = 1;
                    q.push(tmp_node);
                    //cout<<"next++"<<endl;
                    next++;
                }
            }
        }
        //cout<<"next:"<<next<<endl;
        cur = next;
        next = 0;
    }
    return false;
}

void mummy_move(node& tmp)
{
    int moves = 0;
    while(tmp.mu.y!=tmp.man.y)
    {
        if(tmp.mu.y>tmp.man.y)
        {
            if(puzzle[tmp.mu.x][tmp.mu.y-1]==-1)
                return;
            tmp.mu.y-=2;
            moves++;
        }
        else
        {
            if(puzzle[tmp.mu.x][tmp.mu.y+1]==-1)
                return;
            tmp.mu.y+=2;
            moves++;
        }
        if(moves==2)
            return;
    }
    while(tmp.mu.x!=tmp.man.x)
    {
        if(tmp.mu.x>tmp.man.x)
        {
            if(puzzle[tmp.mu.x-1][tmp.mu.y]==-1)
                break;
            tmp.mu.x-=2;
            moves++;
        }
        else
        {
            if(puzzle[tmp.mu.x+1][tmp.mu.y]==-1)
                break;
            tmp.mu.x+=2;
            moves++;
        }
        if(moves==2)
            return;
    }
}

void init(node& ori)
{
    memset(puzzle, 0, sizeof(puzzle));
    int walls;
    int x, y, pos;
    cin>>walls;
    for(int i = 0; i<walls; i++)
    {
        cin>>x>>y>>pos;
        if(pos == 0)
            puzzle[x*2+1][y*2]=-1;
        else
            puzzle[x*2][y*2+1]=-1;
    }
    cin>>ori.mu.x>>ori.mu.y;
    cin>>ori.man.x>>ori.man.y;
    ori.man.x*=2, ori.man.y*=2;
    ori.mu.x*=2, ori.mu.y*=2;
    cin>>x>>y;
    puzzle[x*2][y*2]=1;
}

