#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define maxs 2000010
using namespace std;
int n;
int f[maxs];
int tong[maxs];
pair <int,int> a[maxs],b[maxs];
int t;

int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

int ef(int l,int r,int s){
    int pp;
    if (l >= r)    return l;
    int mid = (l + r) >> 1;
    if (tong[mid] >= s)    pp = ef(l,mid,s);
    if (tong[mid] < s) pp = ef (mid+1,r,s);
    return pp;
}

int main() {
    scanf("%d",&t);
    while (t--){
        bool bo = true;
        int t1 = 0,t2 = 0,tot = 0;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            int x,y,p;
            scanf("%d%d%d",&x,&y,&p);
            if (p) a[++t1] = make_pair(x,y);
                else b[++t2] = make_pair(x,y);
                tong[++tot] = x;
                tong[++tot] = y;
                
        }
        sort(tong,tong + tot + 1);
        unique(tong, tong + tot + 1);
        for (int i = 1; i <= tot; i++)    
            f[i] = i;
        for (int i = 1; i <= t1; i++) {
            int x = ef(1,tot,a[i].second), y = ef(1,tot,a[i].first);
            f[find(x)] = find(y);
            find(x);
        }    
        for (int i = 1; i <= t2; i++) {
            int x = ef(1,tot,b[i].second), y = ef(1,tot,b[i].first);
            if (find(x) == find(y)) {
                bo = false;
                break;
            }
        }
        if (bo)    printf("YES\n");    else printf("NO\n");
    }
    return 0;
}