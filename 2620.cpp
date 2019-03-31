#include <iostream>
#include <algorithm>
#define maxn 5005

struct node {
	int x,y,ans;
} trench[maxn];

bool cmp(const node& a,const node& b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int n;
int sum[maxn];

int main() {
	std :: cin >> n; 
	for(int i = 1;i <= n;i ++) std :: cin >> trench[i].x >> trench[i].y;
	std :: sort(trench + 1, trench + n + 1,cmp);
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j < i;j ++)
			if(trench[j].y <= trench[i].y) trench[i].ans ++;
		sum[trench[i].ans] ++;
	}
    //for(int i = 1;i <= n;i ++) std :: cout << trench[i].x << " " << trench[i].y << " " << trench[i].ans << "\n";
	for(int i = 0;i < n;i ++) std :: cout << sum[i] << "\n";
}
