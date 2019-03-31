#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
#include <climits>

#define MAXN 15
#define update() ans = min(ans, dfs() + 1)

using namespace std;

int Hand[MAXN];

inline long long zip () {
	long long s = 0;
	for (int i = 0; i < MAXN; i++) {
		s = s * 5 + Hand[i];
	}
	return s;
}

tr1::unordered_map<long long, int> S;

int dfs() {
	long long s = zip();
	if (s == 0) return 0;
	if (S.count(s)) return S[s];

	int ans = INT_MAX;
	bool SSingle = true;

	if (Hand[0] && Hand[1]) {              //先出对王
		Hand[0] = Hand[1] = 0;
		update();
		Hand[0] = Hand[1] = 1;

		SSingle = false;                   //为回溯做准备
	}

	//34567
	for (int i = 3; i < MAXN - 4; i++) {   //搜顺子
		bool flag = false;
		for (int d = 0; d < 5; d++) {
			if (!Hand[i + d]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		for (int d = 0; d < 5; d++) Hand[i + d]--;
		
		update();

		int j;
		for (j = i + 5; j < MAXN && Hand[j]; j++) {
			Hand[j]--;
			update();
		}
		
		for (int k = i; k < j; k++) Hand[k]++;    //为回溯做准备

		SSingle = false;
	}

	//334455
	for (int i = 3; i < MAXN - 2; i++) {
		bool flag = false;
		for (int d = 0; d < 3; d++) 
			if (Hand[i + d] < 2) {
				flag = true;
				break;
			}
		if (flag) continue;

		for (int d = 0; d < 3; d++) Hand[i + d] -= 2;

		update();

		int j;
		for (j = i + 3; j < MAXN && Hand[j] >= 2; j++) {
			Hand[j] -= 2;
			update();
		}

		for (int k = i; k < j; k++) Hand[k] += 2;

		SSingle = false;
	}

	//333444
	for (int i = 3; i < MAXN - 1; i++) {
		bool flag = false;
		for (int d = 0; d < 2; d++)
			if (Hand[i + d] < 3) {
				flag = true;
				break;
			}
		if (flag) continue;

		for (int d = 0; d < 2; d++) Hand[i + d] -= 3;

		update();

		int j;
		for (j = i + 2; j < MAXN && Hand[j] >= 3; j++) {
			Hand[j] -= 3;
			update();
		}

		for (int k = i; k < j; k++) Hand[k] += 3;

		SSingle = false;
	}

	//3 + x
	for (int i = 2; i < MAXN; i++)
		if (Hand[i] >= 3) {
			Hand[i] -= 3;

			update();

			for (int j = 0; j < MAXN; j++)
				if (Hand[j] >= 1) {
					Hand[j]--;
					update();
					Hand[j]++;
				}

			for (int j = 2; j < MAXN; j++)
				if (Hand[j] >= 2) {
					Hand[j] -= 2;
					update();
					Hand[j] += 2;
				}

			Hand[i] += 3;

			SSingle = false;
		}

	//4 + x
	for (int i = 2; i < MAXN; i++)
		if (Hand[i] == 4) {
			Hand[i] -= 4;

			update();

			for (int j = 0; j < MAXN; j++) if (Hand[j] >= 1){
				Hand[j]--;
				for (int k = 0; k < MAXN; k++) if (Hand[k] >= 1) {
					Hand[k]--;

					update();

					Hand[k]++;
				}
				Hand[j]++;
			}

			for (int j = 2; j < MAXN; j++) if (Hand[j] >= 2) {
				Hand[j] -= 2;
				for (int k = 2; k < MAXN; k++) if (Hand[k] >= 2) {
					Hand[k] -= 2;

					update();

					Hand[k] += 2;
				}
				Hand[j] += 2;
			}

			Hand[i] += 4;

			SSingle = false;
		}

	for (int i = 2; i < MAXN; i++) if (Hand[i] >= 2) {
		Hand[i] -= 2;
		update();
		Hand[i] += 2;

		SSingle = false;
	}

	if (SSingle) {
		ans = 0;
		for (int i = 0; i < MAXN; i++) {
			ans += Hand[i];
		}
	}

	return S[s] = ans;
}

int main () {
	int T, n;
	scanf("%d %d", &T, &n);
	while (T--) {
		memset(Hand, 0, sizeof(Hand));
		S.clear();
		for (int i = 0; i < n; i++) {
			int x, y; scanf("%d %d", &x, &y);
			if (x == 0) Hand[y - 1]++;         //0、1用来储存大小王
			else if (x == 1) Hand[14]++;       //第14位储存1
			else Hand[x]++;                    //其他手牌正常储存
		}

		printf("%d\n", dfs());
	}

	return 0;
}
