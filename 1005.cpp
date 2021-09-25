#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool backtrack(int c1, int c2, int n, vector<int> weight, int depth);
int main()
{
    int c1, c2, n;
    while(cin>>c1>>c2>>n)
    {
        if(!n)
            return 0;
        vector<int> weight(n);
        for(int i=0; i<n; i++)
            cin>>weight[i];
        sort(weight.rbegin(), weight.rend()); 
        if(backtrack(c1,c2,n,weight,0))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

}


bool backtrack(int c1, int c2, int n, vector<int> weight, int depth)
{
    if(depth==weight.size())
    {
        if(c1>=0&&c2>=0)
            return true;
        else
            return false;
    }
    if(c1<0||c2<0)
        return false;
    bool flag1=false, flag2=false;
    int newc1=c1-weight[depth], newc2=c2-weight[depth];
    if(newc1>=0)
        flag1=backtrack(newc1,c2,n,weight,depth+1);
    if(newc2>=0)
        flag2=backtrack(c1,newc2,n,weight,depth+1);
    return flag1||flag2;
}