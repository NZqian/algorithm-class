#include <iostream>
#include <vector>

using namespace std;

void show(vector<int>& va)
{
    for(int i = 0; i < va.size(); i++)
        cout<<va[i]<<endl;
}
int main()
{
    int n;
    cin>>n;
    int ins;
    vector<int> va(n);
    for(int i = 0; i < n; i++)
        cin>>va[i];
    cin>>ins;
    if(ins>va[n-1])
    {
        va.push_back(ins);
        show(va);
        return 0;
    }
    else if(ins < va[0])
    {
        va.insert(va.begin(), ins);
        show(va);
        return 0;
    }
    for(int i = 0; i < n-1; i++)
    {
        if(va[i] < ins &&va[i + 1] > ins)
        {
            va.insert(va.begin() + i + 1, ins);
            show(va);
            return 0;
        }
    }
}
