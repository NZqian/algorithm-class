#include<iostream>
#include<vector>
using namespace std;
void show(int arr[][3]);
int search(int arr[][3], int n, vector<int> nums);
bool isvalid(int arr[][3]);
int main()
{
	vector<int> nums(9);
	for (int i = 0; i <= 8; i++)
		nums[i] = i + 1;
	int arr[3][3] = { 0 };
    search(arr,0,nums);
}
int search(int arr[][3], int n, vector<int> nums)
{
	if (n == 9)
	{
		if (isvalid(arr))
		{
			show(arr);
			return 0;
		}
		else
		{
			return -1;
		}
	}
    if(n>=3)
        if((arr[0][0]+arr[0][1]+arr[0][2])!=15)
            return -1;
    if(n>=6)
        if((arr[1][0]+arr[1][1]+arr[1][2])!=15)
            return -1;
    if(n>=7)
        if((arr[0][0]+arr[1][0]+arr[2][0])!=15)
            return -1;
    if(n>=8)
        if((arr[0][1]+arr[1][1]+arr[2][1])!=15)
            return -1;
	int x = n / 3, y = n % 3;
	for (int i = 0; i < nums.size(); i++)
	{
		int cur = nums[i];
		arr[x][y] = cur;
		nums.erase(nums.begin() + i);
		search(arr, n + 1, nums);
		nums.insert(nums.begin() + i, cur);
	}
	return 0;
}
bool isvalid(int arr[][3])
{
	int r1 = 0, r2 = 0, r3 = 0, c1 = 0, c2 = 0, c3 = 0, x1 = 0, x2 = 0;
	for (int i = 0; i < 3; i++)
	{
		r1 += arr[0][i];
		r2 += arr[1][i];
		r3 += arr[2][i];
		c1 += arr[i][0];
		c2 += arr[i][1];
		c3 += arr[i][2];
		x1 += arr[i][i];
		x2 += arr[i][2 - i];
	}
	if (r1 == 15 && r2 == 15 && r3 == 15 && c1 == 15 && c2 == 15 && c3 == 15 && x1 == 15 && x2 == 15)
		return true;
	return false;
}
void show(int arr[][3])
{
    int j;
	for (int i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout <<arr[i][j]<< endl;
	}
	cout << endl;
}