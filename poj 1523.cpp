#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
#define maxn 1008  
int first[maxn],vis[maxn],dfn[maxn],low[maxn],cut[maxn];  
int cnt,e,root;  
int vv[maxn*10],nxt[maxn*10];  
void addEdge(int u,int v)  
{  
    vv[e] = v;  nxt[e] = first[u];  first[u] = e++;  
    vv[e] = u;  nxt[e] = first[v];      first[v] = e++;  
}  
inline int min(int a,int b)  
{  
    return a>b?b:a;  
}  
inline int max(int a,int b)  
{  
    return a>b?a:b;  
}  
void Tarjan(int u,int fa)  
{  
    int child = 0;  
    vis[u] = 1;  
    dfn[u] = low[u] = ++ cnt;  
    for(int i = first[u];i != -1;i = nxt[i])  
    {  
        int v = vv[i];  
        if(vis[v] == 1 && v != fa)  
        {  
            low[u] = min(low[u],dfn[v]);  
        }  
        if(vis[v] == 0)  
        {  
            Tarjan(v,u);  
            child++;  
            low[u] = min(low[u],low[v]);  
            if((u == root && child > 1) || (u != root && dfn[u] <= low[v]))  
                cut[u]++;  
        }  
    }  
    vis[u] = 2;  
}  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    int u,v;  
    memset(vis,0,sizeof(vis));  
    memset(cut,0,sizeof(cut));  
    memset(first,-1,sizeof(first));  
    memset(dfn,0,sizeof(dfn));  
    int ans = 0,cas = 0,ok = 0;  
    while(scanf("%d",&u)!=EOF)  
    {  
        if(u == 0 && ok)   
        {  
            cas++;  
            for(int i = 1;i <= 1000;i++)  
            {  
                if(!dfn[i])  
                {  
                    root = i;  
                    cnt = 0;  
                    Tarjan(i,-1);  
                }  
            }  
            printf("Network #%d\n",cas);  
            bool flag = false;  
            for(int i = 1;i <= 1000;i ++)  
            {  
                if(cut[i])    
                {  
                    flag = true;  
                    printf("  SPF node %d leaves %d subnets\n",i,cut[i]+1);  
                }  
            }  
            if(!flag) printf("  No SPF nodes\n");  
            printf("\n");  
            ans = e = cnt = ok = 0;  
            memset(vis,0,sizeof(vis));  
            memset(cut,0,sizeof(cut));  
            memset(first,-1,sizeof(first));  
            memset(dfn,0,sizeof(dfn));  
        }  
        else   
        {  
            ok++;  
            scanf("%d",&v);  
            addEdge(u,v);  
        }  
    }  
    return 0;  
}  

