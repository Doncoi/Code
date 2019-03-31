#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 55

char s[MAXN];
int n, f[MAXN][MAXN][2];
 
bool judge(int l, int r) {
    int mid = (r - l + 1) >> 1;
    for(int i = 0; i < mid; ++ i) 
    	if(s[l + i] != s[l + mid + i]) return false;
    return true;
}
 
int DFS(int L, int R, int t) {
    if(f[L][R][t] != -1) return f[L][R][t];
    if(L == R) return f[L][R][t] = 1;
    int x = R - L + 1, len = x;
    if(t) for(int i = L; i < R; ++ i) 
        x = std :: min(x, DFS(L, i, 1) + 1 + DFS(i + 1, R, 1));
    for(int i = L; i < R; ++ i) 
    	x = std :: min(x, DFS(L, i, t) + R - i);
    if(len % 2 == 0 && judge(L, R)) 
    	x = std :: min(x, DFS(L, L + len/2 - 1, 0) + 1);
    return f[L][R][t] = x;
}
 
int main() {
    scanf("%s", &s); 
    n = strlen(s);
    memset(f, -1, sizeof(f));
    printf("%d\n", DFS(0, n - 1, 1));
    return 0;
}
