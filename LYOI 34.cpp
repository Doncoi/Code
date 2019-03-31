#include <cstdio>
#include <algorithm>
#define MAXN 200000

struct KeyPoint {
	int position, value;

	bool operator<(const KeyPoint &other) const {
		if (position == other.position) return value > other.value;
		else return position < other.position;
	}
} take[MAXN * 2];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d %d", &take[i].position, &take[i + m].position), take[i].value = 1, take[i + m].value = -1;
	std::sort(take, take + m * 2);
	int ans = 0, cur = 0;
	for (int i = 0; i < m * 2; i++) {
		cur += take[i].value;
		ans = std::max(ans, cur);
	}
	printf("%d\n", ans);
}