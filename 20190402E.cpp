#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
struct chi
{
    int a,b,sum;
};
int chu(int a)
{   if(!(a%3))
        return 3;
    if(!(a%2))
        return 2;
    return 0;
}
int main()
{
    chi a;
    while(cin>>a.a)
    {
        cin>>a.b;
        queue<chi>q;
        a.sum=0;
        q.push(a);
        bool flag=false;
        int f[2]={2,3};
        map<int,map<int,bool> >m;
        while(!q.empty())
        {
            a=q.front();
            q.pop();
            if(a.a==a.b)
            {
                flag=true;
                break;
            }
            chi b;
                for(int i=0;i<2;++i)
                {
                    if(!(a.a%f[i]))
                    {
                        b.a=a.a/f[i];
                        b.b=a.b;
                        if(!m[b.a][b.b])
                        {
                            b.sum=a.sum+1;
                            m[b.a][b.b]=true;
                            q.push(b);
                        }
                    }
                }
                for(int i=0;i<2;++i)
                {
                    if(!(a.b%f[i]))
                    {
                        b.b=a.b/f[i];
                        b.a=a.a;
                        if(!m[b.a][b.b])
                        {
                            m[b.a][b.b]=true;
                            b.sum=a.sum+1;
                            q.push(b);
                        }
                    }
                }
        }
        if(flag)
            cout<<a.sum<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}