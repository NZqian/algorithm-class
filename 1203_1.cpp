#include <iostream>
using namespace std;

int C(int up, int down);
int A(int up, int down);

int main()
{
	int M, N;
	cin>>M>>N;
	cout<<C(N-1, M+N-1)/A(N, N)<<endl;
}

int C(int up, int down)
{
	long long ans=1;
	for(int i = 0; i < up; i++)
		ans *= down-i;
	for(int i = 2; i <= up; i++)
		ans /=i;
	return ans;
}

int A(int up, int down)
{
	long long ans=1;
	for(int i = 0; i < up; i++)
		ans *= down-i;
	return ans;
}
