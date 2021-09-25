#include <iostream>

using namespace std;

bool conflict(int curtop, int top, int curcolor, int line, int links[][2], int top_color[]);
void search(int curtop, int top, int color, int line,
            int links[][2], int top_color[], int& ans);
int main()
{
    int top, line, color, ans = 0;
    cin >> top >> line >> color;
    int links[200][2], top_color[21];
    for (int i = 0; i < line; i++)
        cin >> links[i][0] >> links[i][1];
    search(0, top, color, line, links, top_color, ans);
    cout << ans << endl;
}

void search(int curtop, int top, int color, int line,
            int links[][2], int top_color[], int& ans)
{
    if (curtop == top)
    {
        //cout<<"end"<<endl;
        ans++;
        return;
    }
    for (int i = 1; i <= color; i++) //当前颜色i
    {
        for (int i = curtop; i < top; i++)
            top_color[i] = 0;
        top_color[curtop] = i;
        //cout << curtop << ' ' << i << endl;
        if (!conflict(curtop, top, i, line, links, top_color))
        {

            search(curtop + 1, top, color, line, links, top_color, ans);
        }
    }
}

bool conflict(int curtop, int top, int curcolor, int line, int links[][2], int top_color[])
{
    for (int i = 0; i < line; i++)
    {
        if (links[i][0] == curtop && top_color[links[i][1]] == curcolor)
        {
            //cout << "1conflict " << links[i][1] << ' ' << top_color[links[i][1]] << ' ' << curcolor << endl;
            return true;
        }
        else if (links[i][1] == curtop && top_color[links[i][0]] == curcolor)
        {
            //cout << "2conflict " << links[i][0] << ' ' << top_color[links[i][0]] << ' ' << curcolor << endl;
            return true;
        }
    }
    return false;
}
