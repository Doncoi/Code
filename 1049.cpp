#include <cstdio>
#include <climits>
#include <cstring>

#define min(a, b) ((a) < (b) ? (a) : (b))

const int N = 5;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int bx[N * N + 1], by[N * N + 1], size, ans = INT_MAX;
bool a[N + 1][N + 1], vis[N + 1][N + 1];

void find(int x, int y) {
	vis[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (a[nx][ny] && !vis[nx][ny]) find(nx, ny);
	}
}

inline bool check(void) {
	memset(vis, false, sizeof(vis));
	
	int cnt = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) if (a[i][j] && !vis[i][j]) {
			cnt++;
			find(i, j);
		}
	}
	
	return cnt == 1;
}

void dfs(int x, int y) {
	if (y > ans) return;
	
	if (x == size + 1) {
		if (check()) ans = min(ans, y);
		
		return;
	}
	
	a[bx[x]][by[x]] = 1;
	dfs(x + 1, y + 1);	
	a[bx[x]][by[x]] = 0;
	
	dfs(x + 1, y);
}

int main(int argc, char *argv[]) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			char col;
			scanf("\n %c", &col);
			
			a[i][j] = col - '0';
			
			if (col == '0') {
				size++;
				bx[size] = i;
				by[size] = j;
			}
		}
	}
	
	dfs(1, 0);
	printf("%d\n", ans);
	
	return 0;
}

