#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 5

const char Des[5][5] = {{'1', '1', '1', '1', '1'},
					    {'0', '1', '1', '1', '1'},
					    {'0', '0', '0', '1', '1'},
					    {'0', '0', '0', '0', '0'},
					    {'0', '0', '0', '0', '0'}};
const int Move[8][2] {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int T_T, Dep, stx, sty;
char cur[MAXN][MAXN];

inline bool check(const int &x, const int &y) {
	return x >= 0 && x <= 4 && y >= 0 && y <= 4;
}

inline int H() {
	int res = -1;
	for(int i = 0; i <= 4; ++ i) {
		for(int j = 0; j <= 4; ++ j) {
			if(cur[i][j] != Des[i][j]) {
				++ res;
			}
		} 
	} 
	
	return res;
}

inline bool dfs(const int &step, const int &x, const int &y) {
	if(step > Dep) {
		if(H() == -1) {
			return true;
		} else {
			return false;
		}
	}

	if(H() + step - 1 > Dep) {
		return false;
	}
	for(int i = 0; i <= 7; ++ i) {
		int dx = x + Move[i][0], dy = y + Move[i][1];
		if(check(dx, dy)) {
			std :: swap(cur[x][y], cur[dx][dy]);
			if(dfs(step + 1, dx, dy)) {
				return true;
			}
			std :: swap(cur[x][y], cur[dx][dy]);
		}
	}

	return false;
}

int main() {
	scanf("%d", &T_T);
	while(T_T --) {
		for(int i = 0; i <= 4; ++ i) {
			scanf("%s", cur[i]);
		}
	 
		for(int i =0; i <= 4; ++ i) {
			for(int j = 0; j <= 4; ++ j) {
				if(cur[i][j] == '*') {
					stx = i, sty = j;
					break;
				}
			}
		}

		for(Dep = 0; Dep <= 15; ++ Dep) {
			if(dfs(1, stx, sty)) {
				break;
			}
		}

		if(Dep > 15) {
			printf("-1");
		} else {
			printf("%d\n", Dep);
		}
	}

	return 0;
}
