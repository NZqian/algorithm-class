#include <iostream>
#include <memory.h>
#include <queue>
#include <map>

using namespace std;

struct point{
    int x, y;
    point (){}
    point (int a, int b)
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

class node
{
public:
    point man, box;
};

void input(char grid[][10], node& origin, point& aim_pos);
node move_to(node cur_node, int method);
bool is_possible(node cur_node, char grid[][10]);
int bfs(char grid[][10], node origin, point aim_pos);

int main()
{
    char grid[10][10];
    point aim_pos;
    node origin;
    input(grid, origin, aim_pos);
    if(origin.box.x == aim_pos.x&&origin.box.y == aim_pos.y)
    {
       cout<<0<<endl;
        return 0;
    }
    cout<<bfs(grid, origin, aim_pos)<<endl;
    //cout<<endl;
    //for(int i = 0; i<10; i++)
    //{
    //    for(int j= 0; j<10; j++)
    //    {
    //        cout<<grid[i][j];
    //    }
    //    cout<<endl;
    //}
    //cout<<endl<<aim_pos.x<<' '<<aim_pos.y<<endl;
    //cout<<origin.man.x<<' '<<origin.man.y<<endl<<origin.box.x<<' '<<origin.box.y<<endl;
}

int bfs(char grid[][10], node origin, point aim_pos)
{
    int ans = 0, cur = 1, next = 0;
    queue<node> q;
    q.push(origin);
    bool visited[10][10][10][10];
    memset(visited, false, sizeof(visited));
    visited[origin.man.x][origin.man.y][origin.box.x][origin.box.y] = true;
    while(!q.empty())
    {
        while(cur)
        {   
            node cur_node = q.front(), next_node;
            q.pop();
            cur--;
            for(int i = 0; i<4; i++)
            {
                next_node = move_to(cur_node, i);
                //cout<<next_node.man.x<<' '<<next_node.man.y<<' '<<next_node.box.x<<' '<<next_node.box.y<<endl;
                if(is_possible(next_node, grid))
                {
                    if(next_node.box.x == aim_pos.x&&
                       next_node.box.y == aim_pos.y)
                    {
                        ans++;
                        return ans;
                    }
                    if(!visited[next_node.man.x][next_node.man.y][next_node.box.x][next_node.box.y])
                    {
                        q.push(next_node);
                        visited[next_node.man.x][next_node.man.y][next_node.box.x][next_node.box.y] = true;
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

void input(char grid[][10], node& origin, point& aim_pos)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            char tmp;
            cin >> tmp;
            switch(tmp)
            {
            case '2':
                {
                    origin.box = point(i, j);
                    grid[i][j] = '0';
                    break;
                }
            case '4':
                {
                    origin.man = point(i, j);
                    grid[i][j] = '0';
                    break;
                }
            case '3':
                {
                    aim_pos = point(i, j);
                    grid[i][j] = '0';
                    break;
                }
            default:
                grid[i][j] = tmp;
            }
        }
    }
}
                                            
node move_to(node cur_node, int method)        
{                                       
    point near[4] = {point(0 ,-1),          //     1     
                     point(-1, 0),          //     ^     
                     point(0 , 1),          //     |     
                     point(1 , 0)};         //0<- man ->2
    cur_node.man.padd(near[method]);        //     |     
    if(cur_node.man.x == cur_node.box.x&&   //     v     
       cur_node.man.y == cur_node.box.y)    //     3     
        cur_node.box.padd(near[method]);
    return cur_node;
}                                           
                                            
bool is_possible(node cur_node, char grid[][10])
{
    if(cur_node.man.x>=0&&cur_node.man.x<10&&
       cur_node.man.y>=0&&cur_node.man.y<10&&
       cur_node.box.x>=0&&cur_node.box.x<10&&
       cur_node.box.y>=0&&cur_node.box.y<10&&
       grid[cur_node.man.x][cur_node.man.y]!='1'&&
       grid[cur_node.box.x][cur_node.box.y]!='1')
        return true;
    return false;
}
                                            
