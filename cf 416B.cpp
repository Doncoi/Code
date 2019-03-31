#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10005

int n, m;
int a[MAXN], b[MAXN];

inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
    return (res * flag);
}

inline void init() {
    n = read(), m = read();
    for(int i = 1; i <= n; ++ i) a[i] = read();
}

inline void solve() {
    int l, r, x;
    for(int i = 1; i <= m; ++ i) {
        l = read(), r = read(), x = read();
        for(int j = l; j <= r; ++ j) b[j] = a[j];
        //for(int j = l; j <= r; ++ j) printf("%d ",b[j]);
        //printf("\n");
        std :: sort(b + l, b + r + 1);
        //for(int j = l; j <= r; ++ j) printf("%d ",b[j]);
        //printf("\n");
        if(b[x] == a[x]) printf("Yes\n");
        else printf("No\n");
    }
}

int main() {
    init();
    solve();
}
