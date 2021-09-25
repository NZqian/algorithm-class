#include <iostream>

using namespace std;

int r, c;
int height[101][101];
int length[101][101] = {0};
int near[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dp(int x, int y)
{
    if(length[x][y])
    {
        return length[x][y];
        //cout<<x<<' '<<y<<' '<<length[x][y]<<endl;
    }
    int cur_length = 1;
    for(int i = 0; i < 4; i++)
    {
        int tmpx = x + near[i][0];
        int tmpy = y + near[i][1];
        int tmp_length = 1;
        if(tmpx>=0&&tmpx<r&&tmpy>=0&&tmpy<c&&
                height[tmpx][tmpy]<height[x][y])
        {
            tmp_length += dp(tmpx, tmpy);
            if(tmp_length > cur_length)
                cur_length = tmp_length;
        }
    }
    //cout<<x<<' '<<y<<' '<<cur_length<<endl;
    length[x][y] = cur_length;
    return length[x][y];
}
int main()
{
    cin>>r>>c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin>>height[i][j];

    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(dp(i,j)>ans)
                ans = dp(i,j);
    cout<<ans<<endl;
    //for(int i = 0; i < r; i++)
    //{
    //    for(int j = 0; j < c; j++)
    //        cout<<length[i][j]<<' ';
    //    cout<<endl;
    //}
}
