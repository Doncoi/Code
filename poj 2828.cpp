#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define lson l, m, root<<1
#define rson m + 1, r, root<<1|1
const int maxn = 200100;

int sum[maxn << 2];
int x[maxn];

struct Node {
    int p, sr;
} a[maxn];

void pushup(int root) {
    sum[root] = sum[root << 1] + sum[root << 1|1];
}
void build(int l,int r,int root) {
    if(l == r) {
        sum[root] = 1;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(root);
}

void udate(int p,int sr,int l,int r,int root) {
    if(l==r) {
        sum[root]=0;
        x[l]=sr;
        return;
    }
    int m = (l + r)>>1;
    if(p<sum[root<<1])
        udate(p,sr,lson);
    else
        udate(p-sum[root<<1],sr,rson);
    pushup(root);
}
int main() {
    int n,i;
    while(~scanf("%d",&n)) {
        build(0,n-1,1);
        for(i=0;i<n;i++)
        scanf("%d%d",&a[i].p,&a[i].sr);
        build(0,n-1,1);
        for(i=n-1;i>=0;i--) {
            udate(a[i].p,a[i].sr,0,n-1,1);
        }
        for(i=0;i<n-1;i++) {
            printf("%d ",x[i]);
        }
        printf("%d\n",x[i]);
    }
    return 0;
}
