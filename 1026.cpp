#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 55
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, m, k;
int sx, sy, cnt;
int map[MAXN][MAXN];
std :: string s;

struct Node {
	int x, y;
	bool inQueue;
} q[MAXN * MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline void getin(int x, int y) {
	char ch = getchar();
	while(ch == '\n') ch = getchar();
	if(ch == '.') map[x][y] = 1;
	else if(ch == 'X') map[x][y] = 0;
	else map[x][y] = 1, sx = x, sy = y;
}

inline void push(int x, int y) {
	q[++ cnt].x = x, q[cnt].y = y, q[cnt].inQueue = true;
}

inline void walkNorth() {
	int tmp = cnt;
	for(int pre = 1; pre <= tmp; ++ pre) 
		if(q[pre].inQueue) {
			sx = q[pre].x, sy = q[pre].y;

			//printf("Scan (%d, %d) : ", sx, sy);
			q[pre].inQueue = false;

			if(!map[sx - 1][sy]) {
			//	printf("can't go North\n");
				continue;
			}	

			//printf("All Right\n");
			for(int i = sx - 1; i >= 1 && map[i][sy]; -- i) 
			//	printf("Push : (%d, %d)\n", i, sy), push(i, sy);
				push(i, sy); 
		}
}

inline void walkSouth() {
	int tmp = cnt;
	for(int pre = 1; pre <= tmp; ++ pre) 
		if(q[pre].inQueue) {
			sx = q[pre].x, sy = q[pre].y;

			//printf("Scan (%d, %d) : ", sx, sy);
			q[pre].inQueue = false;

			if(!map[sx + 1][sy]) {
			//	printf("can't go Sourth\n");
				continue;			
			}

			//printf("All Right\n");
			for(int i = sx + 1; i <= n && map[i][sy]; ++ i) 
			//	printf("Push : (%d, %d)\n", i, sy), push(i, sy);
			push(i, sy);
		}	
}

inline void walkWest() {
	int tmp = cnt;
	for(int pre = 1; pre <= tmp; ++ pre) 
		if(q[pre].inQueue) {
			sx = q[pre].x, sy = q[pre].y;

			//printf("Scan (%d, %d) : ", sx, sy);
			q[pre].inQueue = false;

			if(!map[sx][sy - 1]) {
			//	printf("can't go West\n");
				continue;
			}

			//printf("All Right\n");
			for(int i = sy - 1; i >= 1 && map[sx][i]; -- i) 
			//	printf("Push : (%d, %d)\n", sx, i), push(sx, i);
			push(sx, i);
		}
}

inline void walkEast() {
	int tmp = cnt;
	for(int pre = 1; pre <= tmp; ++ pre) 
		if(q[pre].inQueue) {
			sx = q[pre].x, sy = q[pre].y;

			//printf("Scan (%d, %d) : ", sx, sy);
			q[pre].inQueue = false;

			if(!map[sx - 1][sy]) {
			//	printf("can't go East\n");
				continue;
			}

			//printf("All Right\n");
			for(int i = sy + 1; i <= m && map[sx][i]; ++ i) 
			//	printf("Push : (%d, %d)\n", sx, i), push(sx, i);
			push(sx, i);
		}
}

void getAns() {
	for(int i = 1; i <= cnt; ++ i) 
		if(q[i].inQueue)
			map[q[i].x][q[i].y] = 2;
}

void outPut() {
	getAns();
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) 
			if(map[i][j] == 0) printf("X");
			else if(map[i][j] == 1) printf(".");
			else if(map[i][j] == 2) printf("*");
		printf("\n");
	}
}

void init() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			getin(i, j);
			
	k = read();
	for(int i = 1; i < MAXN * MAXN; ++ i)
		q[i].inQueue = false;
	cnt = 0, push(sx, sy);
}

void solve() {
	while(k --) {
		std :: cin >> s;
		if(s[0] == 'N') walkNorth();
		else if(s[0] == 'S') walkSouth();
		else if(s[0] == 'W') walkWest();
		else if(s[0] == 'E') walkEast();
	}
	outPut();
}

int main() {
	init();
	solve();
}
