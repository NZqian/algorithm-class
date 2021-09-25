#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>


using namespace std;

int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        double len = 0;
        for(int i=0; i<n; i++)
        {
            double pos = double(i) / n * (m + n);
            len += fabs(int(pos + 0.5) - pos);
        }
        len = len / (m+n) * 10000;
        cout<<fixed<<setprecision(4)<<len<<endl;
    }
}

