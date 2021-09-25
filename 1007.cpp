#include <iostream>
#include <vector>
#include <memory.h>
int cnt=0;
using namespace std;
bool ispossible(char board[][9], int curx, int cury);
void search(char board[][9],int depth);
void show(char board[][9]);
int main()
{
	char board[9][9];
	memset(board, '.', sizeof(board));

	for(int i=1; i<=8; i++)
	{
		board[1][i]='A';
		search(board, 2);
		board[1][i]='.';
	}
}

void search(char board[][9],int depth)
{
	if(depth==9)
	{
		show(board);
		return ;
	}
	for(int i=1; i<=8; i++)
	{
		if(ispossible(board, depth,i))
		{
			board[depth][i]='A';
			search(board, depth+1);
			board[depth][i]='.';
		}
	}
}

void show(char board[][9])
{
	cnt++;
	cout<<"No "<<cnt<<":"<<endl;
	for(int i=1; i<=8; i++)
	{
		for(int j=1; j<=8; j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}

bool ispossible(char board[][9], int curx, int cury)
{
	for(int x=1; x<curx; x++)
	{
		if(board[x][cury]=='A')
			return false;
		if(curx+cury-x<=8&&board[x][curx+cury-x]=='A')
			return false;
		if(cury-curx+x>=1&&board[x][cury-curx+x]=='A')
			return false;
	}
	return true;
}
