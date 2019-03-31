#include <cstdio>
#include <cmath> 
#include <cstring>

double PI = acos(-1.0);    //反余弦函数
double S;

inline double calc(const double &r) {
	double l = (S - r * r) / r;
	double h = sqrt(l * l - r * r);
	double V = PI * r * r * h / 3.0;
	return V;
}

int main() {
	while(scanf("%lf", &S) != EOF) {
		S /= PI;
		double lft = 0, rgt = sqrt(S), m1, m2, r;

		for(int t = 0; t < 200; ++ t) {
			m1 = lft + (rgt - lft) / 3.0;       //左分割点
			m2 = rgt - (rgt - lft) / 3.0;       //右分割点
			if(calc(m1) <= calc(m2)) {       //右割点为好点，最优解在右侧
				lft = m1, r = m2;
			} else {
				rgt = m2, r = m1;
			}
		}

		double l = (S - r * r) / r;
		double h = sqrt(l * l - r * r);
		double V = PI * r * r * h / 3.0;
		printf("%.2f\n%.2f\n%.2f\n", V, h, r);
	}
}
