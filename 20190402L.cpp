#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        n=n+n*(n-1)/2;
        cout<<n<<endl;
    }
    return 0;
}
