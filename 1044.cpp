#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct point{
    int x, y;
    int color;                      //0红, 1黄, 2蓝, 3白, 4绿
    int direction;                  //0东, 1南, 2西, 3北
    char color_char, direction_char;
    point(){}
    point(int x, int y, int color, int direction)
    {
        this -> x = x;
        this -> y = y;
        this -> color = color;
        this -> direction = direction;
    }
    point(int x, int y, int color)
    {
        this -> x = x;
        this -> y = y;
        this -> color = color;
    }
    void init()
    {
        if(color_char == 'R')
            this -> color = 0;
        else if(color_char == 'Y')
            this -> color = 1;
        else if(color_char == 'B')
            this -> color = 2;
        else if(color_char == 'W')
            this -> color = 3;
        else if(color_char == 'G')
            this -> color = 4;
        else
            this -> color = -1;
        if(direction_char == 'E')
            this -> direction = 0;
        else if(direction_char == 'S')
            this -> direction = 1;
        else if(direction_char == 'W')
            this -> direction = 2;
        else if(direction_char == 'N')
            this -> direction = 3;
        else
            this -> direction = -1;
    }
};

int bfs(point start, point end, char grid[][21]);
void move(point& pt, int method);

int main()
{
    point start, end;
    char grid[21][21];
    cin>>start.x>>start.y>>start.color_char>>start.direction_char;
    cin>>end.x>>end.y>>end.color_char;
    start.init();
    end.init();
    for(int i = 1; i<=20; i++)
        for(int j=1; j<=20; j++)
            cin>>grid[i][j];

    //cout<<endl;
    //cout<<start.x<<' '<<start.y<<' '<<start.color<<' '<<start.direction<<endl;
    //cout<<end.x<<' '<<end.y<<' '<<end.color<<' '<<end.direction<<endl;
    //cout<<endl;
    //for(int i = 1; i<=20; i++)
    //{
    //    for(int j=1; j<=20; j++)
    //        cout<<grid[i][j];
    //    cout<<endl;
    //}

    cout<<bfs(start, end, grid)<<endl;
}

int bfs(point start, point end, char grid[][21])
{
    queue<point> q;
    bool visited [21][21][5][4];                 //x, y, color, direction
    visited [start.x][start.y][start.color][start.direction] = true;
    memset(visited, false, sizeof(visited));
    int cur = 1, next = 0, ans = 0;
    q.push(start);
    while(!q.empty())
    {
        while(cur)
        {
            point cur_pt = q.front();
            point tmp_pt = q.front();
            q.pop();
            cur--;
            //cout<<"cur point: "<<cur_pt.x<<' '<<cur_pt.y<<' '<<cur_pt.color<<' '<<cur_pt.direction<<"ans = "<<ans<<endl;
            visited[cur_pt.x][cur_pt.y][cur_pt.color][cur_pt.direction] = true;
            for(int i = 1; i<=3; i++)
            {
                tmp_pt = cur_pt;
                move(tmp_pt, i);
                if(tmp_pt.x>=0&&tmp_pt.x<20&&
                   tmp_pt.y>=0&&tmp_pt.y<20&&
                   grid[tmp_pt.x][tmp_pt.y]=='.')
                {
                    if(tmp_pt.x == end.x && tmp_pt.y == end.y && tmp_pt.color == end.color)
                    {
                        ans++;
                        return ans;
                    }
                    if(!visited[tmp_pt.x][tmp_pt.y][tmp_pt.color][tmp_pt.direction])
                    {
                        //cout<<tmp_pt.x<<' '<<tmp_pt.y<<' '<<tmp_pt.color<<' '<<tmp_pt.direction<<endl;
                        visited[tmp_pt.x][tmp_pt.y][tmp_pt.color][tmp_pt.direction] = true;
                        q.push(tmp_pt);
                        next++;
                    }
                }

            }
        }
        cur = next;
        next = 0;
        ans++;
    }
    return -1;
}

void move(point& pt, int method)
{
    if(method == 1)
    {
        if(pt.direction == 0)
            pt.y++;
        else if(pt.direction == 1)
            pt.x++;
        else if(pt.direction == 2)
            pt.y--;
        else if(pt.direction == 3)
            pt.x--;
        pt.color = pt.color + 1 < 5 ? pt.color + 1 : 0;
    }
    else if(method == 2)
    {
        pt.direction = pt.direction - 1 >= 0 ? pt.direction - 1 : pt.direction + 3;
    }
    else if(method == 3)
    {
        pt.direction = pt.direction + 1 < 4 ? pt.direction + 1 : 0;
    }
}