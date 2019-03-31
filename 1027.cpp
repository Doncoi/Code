#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#define MAXN 25
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n, cnt, sum, tmp;
int f[MAXN][MAXN];
std :: string name[MAXN], id[MAXN], s;

struct Node {
	int b, into, br, ans;
	bool vis, add, bb;
} node[MAXN];

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
	return (res * flag);
}

inline int check() {
	for(int i = 1; i <= cnt; ++ i)
		if(name[i] == s) return i;
	return -1;
}

inline int checkID() {
	for(int i = 1; i <= n; ++ i)
		if(id[i] == s) return i;
}

inline bool find(int key) {
	for(int i = 1; i <= n; ++ i)
		if(!node[i].vis && f[key][i]) {
			node[i].vis = true;
			if(!node[i].b || find(node[i].b)) {
				node[i].b = key;
				return true;
			}
		}

	return false;
}

inline void visClear() {
	for(int i = 0; i < MAXN; ++ i)
		node[i].vis = false;
}

void init() {
	memset(f, 1, sizeof(f));
	n = read();
	for(int i = 1; i <= n; ++ i)
		std :: cin >> id[i];

	char ch[0];
	scanf("%s", ch);
	while(ch[0] != 'Q') {
		if(ch[0] == 'E') {
			std :: cin >> s;
			if((tmp = check()) == -1) 
				name[++ cnt] = s, node[cnt].into = 1;
			else 
				node[tmp].into = 1;
		} else if(ch[0] == 'L') {
			std :: cin >> s;
		    node[tmp = check()].into = 0;
		} else if(ch[0] == 'M') {
			std :: cin >> s;
			tmp = checkID();
			for(int i = 1; i <= n; ++ i) 
				if(!node[i].into) f[i][tmp] = 0;
		}
		scanf("%s", ch);
	}
}

void solve() {
	for(int i = 1; i <= n; ++ i) 
		visClear(), find(i);

	for(int i = 1; i <= n; ++ i) 
		if(node[i].b > 0) {
			visClear();

			for(int j = 1; j <= n; ++ j) 
				node[j].br = node[j].b;
			f[node[i].b][i] = 0;
			node[i].b = 0;

			if(!find(node[i].br)) 
				node[node[i].br].ans = i;
			
			for(int j = 1; j <= n; ++ j)
				node[j].b = node[j].br;
			f[node[i].b][i] = 1;
		}

	tmp = 0;
	for(int i = 1; i <= n; ++ i) {
		s = "";
		for(int j = 1; j <= n; ++ j)
			if(!node[j].bb && (s == "" || name[j] < s)) 
				s = name[j], tmp = j;
			node[tmp].bb = 1;
			std :: cout << s << ":";

			if(node[tmp].ans) std :: cout << id[node[tmp].ans] << std :: endl;
			else std :: cout << "???" << std :: endl;
	}
}

int main() {
	init();
	solve();
}
