#include <iostream>
#include <memory.h>
using namespace std;
int main()
{//1win, 0lose
	int n;
	bool result[1001];
	result[1] = 0;
	while(cin>>n)
	{
		if(!n)
			return 0;
		bool flag1, flag2, flag3;
		for(int i = 2; i<= n; i++)
		{
			if(result[i-1] == 0)
				flag1 = false;
			else
				flag1 = true;
			if((i>5&&result[i-5] == 0))
				flag2 = false;
			else
				flag2 = true;
			if((i>10&&result[i-10] == 0))
				flag3 = false;
			else
				flag3 = true;
			if(flag1 && flag2 && flag3)
				result[i] = false;
			else
				result[i] = true;
		}
		if(result[n] == 1)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
}
