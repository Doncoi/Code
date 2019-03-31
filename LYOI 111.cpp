//jokebird By Doncoi
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

struct Node {
	double t, w;
} a[55];

double T, c, s, k;

bool Compare(const Node *a, const Node *b) {
	return a->t < b->t;
}

void eat(double eatin) {
	eatin += 0.5;
	c += std :: sqrt(eatin);
}

void compare(double target) {
	double rom = c * k;
	if(target < rom) {
		return;
	} else {
		if(target < c) {
			double a = target;
			eat(a);
	    } else {
	    	printf("eat AKdalao\n");
	    	return ;
	    }
	}
}

int main() {
	freopen("jokebird.in", "r", stdin);
	freopen("jokebird.out", "w", stdout);

	scanf("%lf %lf %lf %lf", &T, &c, &s, &k);
	while(T --) {
		int n;  scanf("%d", &n);
		for(int i = 1;i <= n;i ++) {
			scanf("%lf %lf", &a[i].w, &a[i].t);
		}
		std :: sort(a + 1, a + n + 1, Compare);

		c *= s;
		for(int i = 1;i <= n;i ++) {
			compare(a[i].w);
		}
	}
	printf("%lf\n", c);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
