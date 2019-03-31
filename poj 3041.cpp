#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 512

int n, m;
int map[MAXN][MAXN];
int matching[MAXN];
bool check[MAXN];

bool dfs(int u) {
    for(int v = 0; v < n; ++ v) {	
        if(map[u][v] && !check[v]) { 
            check[v] = true;
            if(matching[v] == -1 || dfs(matching[v])) {
                matching[v] = u;
                return true;
            }
        }
	}
    
	return false;
}
int hungrian() {
    int cnt = 0;
    memset(matching, -1, sizeof(matching));
    for(int u = 0; u < n; ++ u){
        memset(check, false, sizeof(check));
        if(dfs(u)) {
			cnt ++;
		}
    }
    
    return cnt;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(map, 0, sizeof(map));
        for(int i = 0; i < m; ++ i) {
        	int x, y;
            scanf("%d%d", &x, &y);
            map[--x][--y] = 1;
        }
        
        printf("%d\n", hungrian());
    }
    
    return 0;
}
