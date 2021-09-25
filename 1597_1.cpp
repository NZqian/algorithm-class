#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;//n个点 
int g[500][500];//图的邻接表
int d[500];
int t[500];//集合t 


void init();

int main()
{
	int i, j;
	int mintree, cnt, minn;
	int v;
	
	cin >> n;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}
	
	init();
	
	mintree = 0;
	cnt = 0;
	while(cnt < n - 1)
	{//在未加入到集合t的点中，找距离最小生成树最近的点v，把v加入到集合t中
		 minn = 1000000;
		 for(i = 0; i < n; i++)
		 {
		 	if(t[i] == 0 && d[i] < minn)
		 	{
		 		minn = d[i];
		 		v = i;
		 	}
		 }
		 cnt++;
		 t[v] = 1;
		 mintree += d[v];
		 for(i = 0; i < n; i++)
		 {
		 	if(t[i] == 0 && g[v][i] < d[i])
		 	{
		 		d[i] = g[v][i];
		 	}
		 }
	}
	cout << mintree << endl;
}	


void init()
{
	int i;
	
	t[0] = 1;
	for(i = 0; i < n; i++)
	{
		d[i] = g[0][i];
	}
}
