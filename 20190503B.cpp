#include<iostream>
using namespace std;
int main()
{
    int T;cin>>T;
    for(int s=1;s<=T;++s)
    {
        int h,m,t;
        string city1,city2,time;
        char c;
        cin>>h>>c>>m>>time;
        cin>>city1>>city2;
        h%=12;
        if(time=="PM")
            h+=12;
        if(city1=="Beijing")
            h-=8;
        else if(city1=="Washington")
            h+=5;
        else if(city1=="Moscow")
            h-=3;
        if(city2=="Beijing")
            h+=8;
        else if(city2=="Washington")
            h-=5;
        else if(city2=="Moscow")
            h+=3;
        t=h*60+m;
        cout<<"Case "<<s<<": ";
        if(t<0)
            cout<<"Yesterday ";
        else if(t>=0&&t<1440)
            cout<<"Today ";
        else if(t>=1440)
            cout<<"Tomorrow ";
        while(t<=0)
            t+=1440;
        t%=1440;
        h=(t/60)%12;
        if(h==0)
            h=12;
        printf("%d:%02d ",h,t%60);
        if(t>=720)
            cout<<"PM"<<endl;
        else
            cout<<"AM"<<endl;
    }
    return 0;
}