#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100100;

int b[MAX],mid;
long long ans;
struct tree {
	int left, right;
	long long sum;
} a[MAX * 4];

void build(int x,int y,int p) {
	a[p].left = x;
	a[p].right = y;
	if(x == y)
		a[p].sum=b[x];
	else {
		mid = (a[p].left + a[p].right) / 2;
		build(x, mid, p * 2);
		build((x+y) / 2 + 1, y, p * 2 + 1);
		a[p].sum = a[p * 2].sum + a[p * 2 + 1].sum;
	}
}

void change(int x, int p, int val) {
	a[p].sum = a[p].sum + val;
	if(a[p].left != a[p].right) {
		mid = (a[p].left + a[p].right) / 2;
		if(x <= mid)
			change(x, p * 2, val);
		else
			change(x, p * 2 + 1, val);
	}
}

void find(int x,int y,int p) {
	mid = (a[p].left + a[p].right) / 2;
	if(a[p].left >= x && a[p].right <= y)
		ans = ans + a[p].sum;
	else {
		if(mid >= x)
			find(x,y,p * 2);
		if((a[p].left + a[p].right) / 2 + 1 <= y)
			find(x,y,p * 2 + 1);
	}
}

int main( ) {
	int n, m, d, e;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> b[i];
	}
	build (1, n, 1);
	cin >> m;
	for(int i = 1;i <= m;i ++) {
		int c;
		cin >> c;
		if(c == 1) {
			cin >> d >> e;
			change(d, 1, e);
		}
		else {
			ans = 0;
			cin >> d >> e;
			find(d, e, 1);
			cout << ans << endl;
		}
    }
}
