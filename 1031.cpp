#include <bits/stdc++.h>
#define MAXN 100005

int n;
int pr[MAXN], vis[MAXN];

inline void print() {
	for(int i = 1; i <= n; ++ i)
		std :: cout << pr[i] << ' ';
	std :: cout << std :: endl;
}

inline bool check(int x) {
	for(int i = 2; i * i <= x; ++ i)
		if(x % i == 0) return false;
	return true;
}

void DFS(int dep) {
	if(dep == n && check(pr[1] + pr[n])){
		print(); return;
	}

	for(int i = 2; i <= n; ++ i)
		if(vis[i] == 0 && check(pr[dep] + i)) {
			pr[dep + 1] = i, vis[i] = 1;
			DFS(dep + 1);
			pr[dep + 1] = 0, vis[i] = 0;
		}
}

int main() {
	std :: cin >> n;
	pr[1] = 1, vis[1] = 1;
	DFS(1);
}
