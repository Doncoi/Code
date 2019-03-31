#include <cstdio>
#include <cstring>
#include <algorithm>

int l, r;
int f[20][10], bits[20];

inline int read() {
    char c = getchar();    int res = 0, flag = 1;
    while(c < '0' || c > '9') {if(c == '-') flag = -1;  c = getchar();}
    while(c >= '0' && c <= '9') {res = res * 10 + c - '0'; c = getchar();}
    return res * flag;
}

int dfs(int pos, int pre, bool lmt, bool first) {
    if (pos == -1) return 1;
    if (!lmt && !first && ~f[pos][pre]) return f[pos][pre];
    int u = lmt ? bits[pos] : 9, ret = 0;
    for (int i = 0; i <= u; i++) 
        if (first || (!first && abs(pre - i) >= 2))
            ret += dfs(pos - 1, i, lmt && i == u, first && !i);
    return lmt || first ? ret : f[pos][pre] = ret;
}

int calc(int n) {
    memset(f, -1, sizeof(f));
    int len = 0;
    while (n) {bits[len ++] = n % 10; n /= 10;}
    return dfs(len - 1, 0, true, true);
}

int main() {
    l = read(), r = read();
    printf("%d\n", calc(r) - calc(l - 1));
    return 0;
}