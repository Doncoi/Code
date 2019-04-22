
#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct nai
{
    int a,b,sum;
    nai(int i,int j,int s)
    {
        a=i;b=j;sum=s;
    }
};
int main()
{
    int maxa,maxb,k;
    while(cin>>maxa)
    {
        cin>>maxb>>k;
        nai a(0,0,0);
        map<int,map<int,bool> >m;
        queue<nai>q;
        q.push(a);
        bool flag=false;
        m[0][0]=true;
        while(!q.empty())
        {
            a=q.front();
            if(a.a==k||a.b==k)
            {
                flag=true;
                break;
            }
            q.pop();
            if(a.a<maxa||!m[maxa][a.b])
            {
                nai b(maxa,a.b,a.sum+1);
                m[maxa][a.b]=true;
                q.push(b);
            }
            if(a.b<maxb||!m[a.a][maxb])
            {
                nai b(a.a,maxb,a.sum+1);
                m[a.a][maxb]=true;
                q.push(b);
            }
            if(a.b&&a.a<maxa)
            {
                int x=maxa-a.a;
                x=min(x,a.b);
                nai b(a.a+x,a.b-x,a.sum+1);
                if(!m[b.a][b.b])
                {
                    m[b.a][b.b]=true;
                    q.push(b);
                }
            } 
            if(a.b<maxb&&a.a)
            {
                int x=maxb-a.b;
                x=min(x,a.a);
                nai b(a.a-x,a.b+x,a.sum+1);
                if(!m[b.a][b.b])
                {
                    m[b.a][b.b]=true;
                    q.push(b);
                }
            }
            if(a.a&&!m[0][a.b])
            {
                nai b(0,a.b,a.sum+1);
                m[b.a][b.b]=true;
                q.push(b);
            }
            if(a.b&&!m[a.a][0])
            {
                nai b(a.a,0,a.sum+1);
                m[b.a][b.b]=true;
                q.push(b);
            }
        }
        if(flag)
            cout<<a.sum<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}