
#include<iostream>

using namespace std;

int main()

{

    int a[2002];

    int b[2002];

    int n;

    cin>>n;

    for(int i=0;i<n;i++)

        cin>>a[i];

    for(int i=0;i<n;i++)

        cin>>b[i];

    int ok=0;

     for(int i=0;i<n;i++)ok=ok+a[i];

     for(int i=0;i<n;i++)ok=ok-b[i];

     if(ok<0){cout<<"No Result!";return 0;}

    int result[1000];

    int results=0;

    for(int i=n;i<2*n;i++)

    {a[i]=a[i-n];b[i]=b[i-n];}

    ok=0;

    int j=0;

    aa:

    while(j<n)

    {

        for(int i=j;i<j+n;i++)

        {

            ok+=(a[i]-b[i]);

            if(ok<0){ok=0;j++;goto aa;}

        }

        {result[results]=j+1;results++;ok=0;j++;}

    }

    if(results==0)cout<<"No Result!";

    else for(int i=0;i<results;i++)cout<<result[i]<<' ';



}


