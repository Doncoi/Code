#include <cmath>
#include <cstdio>
#include <algorithm>
#define  MAXN 10005

int n, m;
int ans;

struct Node {
	int x, y;
	Node() {}

	Node(int _x, int _y) : x(_x), y(_y) {}

	friend inline Node operator - (const Node &lhs, const Node &rhs) {
		return Node(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	friend inline int operator * (const Node &lhs, const Node &rhs) {
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	inline int norm() const {
		return x * x + y * y;
	}
	
} p[MAXN], q[MAXN];

inline bool cmp(int u, int v) {
	int tmp = (p[u] - p[1]) * (p[v] - p[1]);
	if(tmp) {
		return tmp > 0;
	}

	return (p[u] - p[1]).norm() < (p[v] - p[1]).norm();
}

void Graham_Scan() {
	int id = 1;              //寻找位于最左下角的极点
	for(int i = 2; i <= n; ++ i) {
		if(p[i].x < p[id].x || (p[i].x == p[id].x && p[i].y < p[id].y)) {
			id = i;
		} 
	}
	std :: swap(p[1], p[id]);

	static int pre[MAXN];             //使用辅助数组储存点的下标并排序
	for(int i = 1; i <= n; ++ i) {
		pre[i] = i;
	}
	std :: sort(pre + 2, pre + n + 1, cmp);  //第一位为我们找到的极点，不参与排序

	q[++ m] = p[1];
	for(int i = 2; i <= n; ++ i) {
		int j = pre[i];
		while(m >= 2 && (p[j] - q[m -1]) * (q[m] - q[m - 1]) >= 0) { //判断拐向
			-- m;  //若发生拐向，则出现了凹边，是当前点出队
		}

		q[++ m] = p[j];
	}
}

void Area() {
	ans =  0;
	q[m + 1] = q[1];
	for(int  i = 1; i <= m; ++ i) {   //多点向量叉积
		ans += q[i] * q[i + 1];
	}

	ans /= 2;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
		
	Graham_Scan();
	Area();
	ans /= 50;
	printf("%d\n", ans);
	return 0;
}
