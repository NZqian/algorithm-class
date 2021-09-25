#include <iostream>

int nums[101][101];
using namespace std;
//m dumplings, n plates
int dp(int m, int n)
{
	if(nums[m][n])
		return nums[m][n];
	else if(n == 1 || m == 0 || m == 1)
	{
		nums[m][n] = 1;
		return nums[m][n];
	}
	else if(n>m)
	{
		nums[m][n] = dp(m, m);
		return nums[m][n];
	}
	else
	{
		nums[m][n-1] = dp(m, n-1);
		nums[m-n][n] = dp(m-n, n);
		nums[m][n] = nums[m][n-1] + nums[m-n][n];
		return nums[m][n];
	}
}

int main()
{
	int m, n;
	cin>>m>>n;
	cout<<dp(m, n)<<endl;
}
