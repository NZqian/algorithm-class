#include <iostream>
#include <memory.h>

using namespace std;

int heap[11];
int binary[11][7];
int n;

void to_binary();

int main()
{
    while(cin>>n&&n)
    {
        memset(heap, 0, sizeof(heap));
        memset(binary, 0, sizeof(binary));
        for(int i = 0; i < n; i++)
            cin>>heap[i];
        to_binary();
        int ans = heap[0];
        for(int i = 1; i< n; i++)
        {
            int cur = heap[i];
            ans ^= cur;
        }
        //cout<<ans<<endl;
        if(!ans)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
}

void to_binary()
{
    for(int i = 0; i < n; i++)
    {
        int cur = heap[i];
        int cnt = 0;
        while(cur)
        {
            binary[i][cnt] = cur % 2;
            cur /= 2;
            cnt ++;
        }
    }
}
