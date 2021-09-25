#include<iostream>
#include<vector>
#include<string>
using namespace std;
void backtrack(string str, int i, int n);
int main()
{
    int n;
    cin >> n;
    string ori;
    for (int i = 0; i < n; i++)
        ori.push_back('a' + i);
    backtrack(ori, 0, n);
}
void backtrack(string str, int i, int n)
{
    if(i==n)
        cout << str << endl;
    for (int j = i; j < n; j++)
    {
            swap(str[i], str[j]);
            backtrack(str, i + 1, n);
            swap(str[i], str[j]);
    }
}