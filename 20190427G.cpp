#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=n;;i++)
        {
            if(!(i%7)&&(i>=7)&&i%4)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
