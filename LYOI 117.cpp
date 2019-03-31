#include <algorithm>
#include <cstring>
#include <cstdio>

#define MAXN 105

int n, m, x, y, ans;
int dis[MAXN][MAXN], fy[MAXN], mat[MAXN], flag[MAXN];

inline bool crosspath(int u) {
    for(int i = m + 1; i <= n; i ++) 
        if(dis[u][i] == 1 && fy[i] == 0) {
            fy[i] = 1;
            if(mat[i] == -1 || crosspath(mat[i])) {
                flag[u] = i;
                mat[i] = u;
                return true;
            }
        }
        
    return false;
}

void hungary() {
    for(int i = 1; i <= m; i ++) 
        if(flag[i] == -1) 
            memset(fy, 0, sizeof(fy)), ans += crosspath(i);
}

int main() {
    scanf("%d %d", &n, &m);
    memset(dis,0,sizeof(dis));
    memset(mat,-1,sizeof(mat));
    memset(flag,-1,sizeof(flag));
    while(scanf("%d %d", &x, &y) != EOF)
        dis[x][y] = 1;
        
    hungary();
    printf("%d\n", ans);
}
