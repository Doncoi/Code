#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 600005;
int n,m,tot = 0,f,t,v,x,ans = 0;
int first[MAXN],nxt[MAXN << 1],dis[MAXN << 1],pre[MAXN];
bool used[MAXN];
struct edge{
    int f,t,v;
}l[MAXN << 1];

void build(int f,int t,int v){
    l[tot] = (edge){f,t,v};
    nxt[tot] = first[f];
    first[f] = tot,tot ++;
}

deque < int > q;
void spfa(int s){
    while(!q.empty()) q.pop_front();
    memset(used,0,sizeof(used));
    memset(dis,0x3f,sizeof(dis));
    used[s] = true;dis[s] = 0;
    q.push_front(s);

    while(!q.empty()){
        int u = q.front(); q.pop_front();
        used[u] = false;
        for(int i = first[u]; i != -1; i = nxt[i]){
            int w = l[i].t; 
            if(dis[w] > dis[u] + l[i].v){
                dis[w] = dis[u] + l[i].v;
                pre[w] = i;
                if(used[w]) continue;
                if(q.empty()) q.push_front(w);
                else if(dis[w] < dis[q.front()]) q.push_front(w);
                else q.push_back(w);  
                used[w] = true;
            }
        }
    }
}

void spfa2(int s,int k){
    while(!q.empty()) q.pop_front();
    memset(used,0,sizeof(used));
    memset(dis,0x3f,sizeof(dis));
    used[s] = true;dis[s] = 0;
    q.push_front(s);

    while(!q.empty()){
        int u = q.front(); q.pop_front();
        used[u] = false;
        for(int i = first[u]; i != -1; i = nxt[i]){
            if(i == k || i == (k ^ 1)) continue;
            int w = l[i].t; 
            if(dis[w] > dis[u] + l[i].v){
                dis[w] = dis[u] + l[i].v;
                if(used[w]) continue;
                if(q.empty()) q.push_front(w);
                else if(dis[w] < dis[q.front()]) q.push_front(w);
                else q.push_back(w);  
                used[w] = true;
            }
        }
    }
}

inline int read(){
    int x = 0,f = 1; char ch = getchar();
    while(!('0' <= ch && ch <= '9')) {if(ch == '-') f = -1; ch = getchar();}
    while('0' <= ch && ch <= '9') {x = x * 10 + (ch - '0'); ch = getchar();}
    return x * f;
}

int main(){
    memset(first,0xff,sizeof(first));
    memset(pre,0xff,sizeof(pre));//端点 和first同样处理 
    n = read(),m = read();
    for(int i = 1; i <= m; i ++){
        f = read(),t = read(),v = read();
        build(f,t,v),build(t,f,v);
    }
    spfa(1), ans = dis[n],x = n;
    while(x){
        spfa2(1,pre[x]);
        ans = max(ans,dis[n]);
        x = l[pre[x]].f;
    }
    printf("%d\n",ans);
    return 0;
}