#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int chart[129][129];
    int size=1;
    while(n--)
        size<<=1;
    for(int i=1; i<=size; i++)
        chart[i][1]=i;
    for(int cursize=2; cursize<=size; cursize<<=1)
    {
        //cout<<"cursize "<<cursize<<endl;
        for(int pos=1; pos<size; pos+=cursize)
        {
            //cout<<"pos "<<pos<<endl;
            int i, j;
            for(i=pos; i<pos+cursize/2; i++)
            {
                //cout<<"i "<<i<<endl;
                for(int k=1; k<=cursize/2; k++)
                {
                    //cout<<"k "<<k<<endl;
                    chart[i+cursize/2][k+cursize/2]=chart[i][k];
                    chart[i][k+cursize/2]=chart[i+cursize/2][k];
                }
            }
        }
    }
    for(int i=1; i<=size; i++)
    {
        int j;
        for(j=1; j<size; j++)
        {
            cout<<chart[i][j]<<" ";
        }
        cout<<chart[i][j];
        cout<<endl;
    }
}