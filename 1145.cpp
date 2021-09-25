#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct point
{
    int x, y;
    point() {}
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
int main()
{
    int m, n, x, y;
    point near1[4] = {point(-1, 0), point(1, 0), point(0, -1), point(0, 1)};
    point near2[4] = {point(-1, -1), point(-1, 1), point(1, -1), point(1, 1)};
    while (1)
    {
        cin >> m >> n >> x >> y;
        if (!m && !n && !x && !y)
            return 0;
        char pic[101][101];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> pic[i][j];
        bool visited[101][101] = {false};
        int ans = 0;
        queue<point> q;
        if (x >= 1 && x <= m && y >= 1 && y <= n&&pic[x][y]=='X')
            q.push(point(x, y));
        while (!q.empty())
        {
            point cur = q.front();
            visited[cur.x][cur.y] = true;
            int tmp = 4;
            for (int i = 0; i < 4; i++) //相邻四块
            {
                cur.padd(near1[i]);
                if (cur.x >= 1 && cur.x <= m && cur.y >= 1 && cur.y <= n)
                {
                    if (pic[cur.x][cur.y] == 'X')
                    {
                        tmp -= 1;
                        if (!visited[cur.x][cur.y])
                        {
                            q.push(cur);
                            visited[cur.x][cur.y] = true;
                        }
                    }
                }
                cur.pminus(near1[i]);
            }
            for (int i = 0; i < 4; i++) //对角四块
            {
                cur.padd(near2[i]);
                if (cur.x >= 1 && cur.x <= m && cur.y >= 1 && cur.y <= n)
                {
                    if (pic[cur.x][cur.y] == 'X')
                    {
                        if (!visited[cur.x][cur.y])
                        {
                            q.push(cur);
                            visited[cur.x][cur.y] = true;
                        }
                    }
                }
                cur.pminus(near2[i]);
            }
            ans += tmp;
            q.pop();
        }
        cout << ans << endl;
    }
}