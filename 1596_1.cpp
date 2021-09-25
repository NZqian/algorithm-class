#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge
{
	int v1;
	int v2;
	int len;
};

int n, m;//n个点, m条边 
struct edge e[100000];//图的所有边

int p[10000];//p[i]=i表示i是根节点

int find(int x);
void myunion(int x, int y);

void init();
bool cmp1(struct edge e1, struct edge e2);

int main()
{
	int i;
	int f1, f2;
	int cnt;
	int mintree;
	
	cin >> n >> m; 
	for(i = 0; i < m; i++)
        cin >> e[i].v1 >> e[i].v2 >> e[i].len;
	init();
	sort(e, e + m, cmp1);
	
	mintree = 0;
	cnt = 0;
	for(i = 0; i < m; i++)
	{
		f1 = find(e[i].v1);
		f2 = find(e[i].v2);
		if(f1 != f2)
		{
			myunion(f1, f2);
			mintree += e[i].len;
			cnt++;
			if(cnt >= n - 1)
			{
				break;
			}
		}
	}
	cout << mintree << endl;
}

int find(int x)
{
	int f;
	
	f = x;
	while(p[f] != f)
	{
		f = p[f];
	}
	return(f);
}

void myunion(int x, int y)
{
	int f1, f2;
	
	f1 = find(x);
	f2 = find(y);
	p[f1] = f2;
}

void init()
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		p[i] = i;
	}
}

bool cmp1(struct edge e1, struct edge e2)
{
	return(e1.len < e2.len);
}
