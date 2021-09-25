#include <iostream>
#include <algorithm>

using namespace std;

struct edge
{
    int v1, v2, len;
};

int p[10000];
edge e[100000];

void merge(int a, int b);
int find(int x);
bool compare(edge a, edge b);

int main()
{
    int n, m, ans = 0, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin>>e[i].v1>>e[i].v2>>e[i].len;
    for(int i = 0; i < n; i++)
        p[i] = i;
    sort(e, e + m, compare);    
    for(int i = 0; i < m; i++)
    {
        int f1 = find(e[i].v1);
        int f2 = find(e[i].v2);
        if(f1 != f2)
        {
            ans += e[i].len;
            merge(f1, f2);
            cnt ++;
            if(cnt == n - 1)
                break;
        }
    }
    cout<<ans<<endl;
}

int find(int x)
{
    int f = x;
    while(p[f] != f)
        f = p[f];
    return f;
}

void merge(int a, int b)
{
    int f1 = find(a);
    int f2 = find(b);
    p[f1] = f2;
}

bool compare(edge a, edge b)
{
    return a.len < b.len;
}
