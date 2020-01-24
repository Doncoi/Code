#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
struct lu
{
    int v;
    long long sum;
    lu(int v,long long s)
    {
        this->v=v;
        sum=s;
    }
    friend bool operator < (const lu a,const lu b)
    {
        return a.sum>b.sum;
    }
};
struct node
{
    int v;
    long long c;
    node(int v,long long c)
    {
        this->v=v;
        this->c=c;
    }
};
vector<node>ma[50005];
//map<int,vector<node> >ma;
long long dist[50005];
int n;
void bfs(int s)
{
    bool use[50005]={false};
    for(int i=0;i<n;++i)
        dist[i]=1000000000000LL;
    priority_queue<lu>q;
    dist[s]=0;
    lu l(s,0);
    q.push(l);
    while(!q.empty())
    {
        l=q.top();
        q.pop();
        if(use[l.v])
            continue;
        use[l.v]=true;
        int u=l.v;
        int size=ma[u].size();
        for(int i=0;i<size;++i)
        {
            int v=ma[u][i].v,c=ma[u][i].c;
            if(!use[v]&&dist[v]>dist[u]+c)
            {
                dist[v]=dist[u]+c;
                lu a(v,dist[v]);
                q.push(a);
            }
        }
    }
}
void add(int a,int b,int c)
{
    node no(b,c);
    ma[a].push_back(no);
}
int main()
{
    int m,f,s,t;
    cin>>n>>m>>f>>s>>t;
    while(m--)
    {
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(a,b,l);
        add(b,a,l);
    }
    bfs(s);
    long long mins=dist[t];
    //cout<<dist[t]<<endl;
    while(f--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b,0);
        bfs(s);
        mins=min(mins,dist[t]);
        //cout<<dist[t]<<endl;
        ma[a].pop_back();
    }
    cout<<mins;
    return 0;
}