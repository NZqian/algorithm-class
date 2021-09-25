#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
	int n;
	int nums[101] = {0};
	int arr[101] = {0};
	while(cin>>n)
	{
		if(n == 0)
			return 0;
		memset(nums, 0, sizeof(nums));
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < n; i++)
			cin>>nums[i];
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			int max = 0;
			for(int j = 0; j <= i - 1; j++)
			{
				if(nums[j] >= nums[i] && arr[j] + 1>max)
					max = arr[j] + 1;
			}
			arr[i] = max > 0 ? max : 1;
			if(arr[i] > ans)
				ans = arr[i];
		}
		cout<<ans<<endl;
	}

}
