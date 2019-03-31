#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};
int n, ID;
int map[10][10], c[10][10];
bool used[6];

int get() {
	int ret = 0;
	memset(used, false,sizeof(used));
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(!used[map[i][j]] && c[i][j] != 1) {
				used[map[i][j]] = true;
				ret ++;
			}
		}
	}

	return ret;
}

void dfs(int x, int y, int color) {
	c[x][y] = 1;
	for(int i = 0;i < 4;i ++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > n || c[nx][ny] == 1) continue;
		c[nx][ny] = 2;
		if(map[nx][ny] == color) {
			dfs(nx, ny, color);
		}
	}
}

int fill(int color) {
	int ret = 0;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			if(c[i][j] == 2 && map[i][j] == color) {
				ret ++;
				dfs(i, j, color);
			}
		}
	}

	return ret;
}

bool IDAstar(int step) {
	int g = get();
	if(step + g > ID) return false;
	if(!g) return true;

	int temp[10][10];
	for(int i = 0;i <= 5;i ++) {
		memcpy(temp, c, sizeof(map));
		if(fill[i] && IDAstar(step + 1)) return true;
		memcpy(c, temp, sizeof(map));
	} 

	return false;
}

int main() {
	while(std :: cin >> n && n) {
		std :: memset(c, 0, sizeof(c));
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= n;j ++) {
				scanf("%d", &map[i][j]);
			}
		}

		dfs(1, 1, map[1][1]);
		for(ID = 0; ; ID ++) {
			if(IDAstar(0)) {
				break;
			}
		}
		std :: cout << ID << std :: endl;
	}
}
