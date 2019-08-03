#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define N 12
#define M 500000
#define inf 1e9
using namespace std;
typedef long long LL;
struct edge{ int nxt,point,v; LL w;};
struct data{ LL value; int id;};
edge e[((N*M)<<1)+5];
data heap[M+5];
LL a[N+5],dis[M + 5],cnt,n,Bmin,Bmax,mini,minist;
void addedge(int u1,int v1,LL w1){ 
    e[++cnt].nxt = e[u1].point; e[u1].point = cnt; e[cnt].v = v1; e[cnt].w = w1;}
//void insert(int u1,int v1){ addedge(u1,v1); addedge(v1,u1);}
inline LL getnum(){
    char c; LL num;
    while (!isdigit(c = getchar()));
    num = c - '0';
    while (isdigit(c = getchar())) num = 10 * num + c - '0';
    return num;
}

void init(){
    n = getnum(); Bmin = getnum(); Bmax = getnum(); cnt = 0;
    for (int i = 1;i <= n; ++i) a[i] = getnum();
    sort(a + 1,a + n + 1);
    mini = a[1];
}

void make_it(){
    for (int i = 0;i < mini; ++i)
      for (int j = 1;j <= n; ++j)
        addedge(i,(i + a[j])%mini,a[j]);
}

inline void push(data x){
    heap[++cnt] = x;
    int j = cnt;
    while (j>1&&heap[j].value < heap[(j>>1)].value) swap(heap[j],heap[j>>1]);
}

inline data pop(){
    data x = heap[1];
    heap[1] = heap[cnt--];
    int j = 1;
    while (1){
        minist = j;
        if ((j<<1)<=cnt) minist = j<<1;
        if ((j<<1|1)<=cnt&&heap[minist].value > heap[(j<<1|1)].value) minist = j<<1|1;
        if (minist == j) break;
        swap(heap[j],heap[minist]);
        j = minist; 
    }
    return x;
}

void heap_dijistra(){
    data tmp = (data) {0,0}; cnt = 0;
    memset(dis,0x7f,sizeof(dis));
    dis[0] = 0; push(tmp); 
    while (cnt){
         data x = pop(); 
         //cout<<x.id<<" "<<x.value<<endl;
         for (int p = e[x.id].point;p ; p = e[p].nxt)
           if (dis[e[p].v] > dis[x.id] + e[p].w){
                dis[e[p].v] = dis[x.id] + e[p].w;
                push((data){dis[e[p].v],e[p].v});
           }
    }
}

inline LL query(LL maxi){
    if (maxi == 0) return 1;
    if (maxi < 0) return 0;
    LL sum = 0; 
    for (int i = 0;i < mini; ++i)
      if (dis[i] <= maxi)
        sum += (maxi - dis[i])/mini + 1;
    return sum;
}

void solve(){
    make_it();
    heap_dijistra();
    //cout<<query(10)<<endl;
    //cout<<query(4);
    cout<<query(Bmax) - query(Bmin - 1);
}

int main(){
    init();
    solve();
}