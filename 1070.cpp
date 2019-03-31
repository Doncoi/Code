#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

int n;
double f0, f1, a, b;

struct Node {
        int x, y;
        double f[6][6];
        Node() { mem(f, 0), x = y = 0;}

        Node operator = (const Node a){
                x = a.x; y = a.y;
                for (int i = 1; i <= a.x; i++)
                        for (int j = 1; j <= a.y; j++)
                                f[i][j] = a.f[i][j];
        }

        Node operator * (const Node a){
                Node b;
                b.x = x, b.y = a.y;
                for (int i = 1; i <= x; i++)
                        for (int j = 1; j<= a.y; j++)
                                for (int k = 1; k <= y; k++)
                                        b.f[i][j] += f[i][k] * a.f[k][j];
                return b;
        }

        Node operator *= (const Node a){
                *this = *this * a;
                return *this;
        }
}ju, ru;

void quicksort(int k) {
        Node pi = ru;
        while (k > 0) {
                if (k & 1) ju *= pi;
                k /= 2;
                pi *= pi;
        }
}

int work() {
        scanf("%lf%lf%lf%lf%d", &f0, &f1, &a, &b, &n);
        if (n == 0) { printf("%.0lf", f0); return 0; }
        if (n == 1) { printf("%.0lf", f1); return 0; }
        if (f0 == 0 && f1 == 0) { printf("0"); return 0; }
        ju.x = 1, ju.y = 2, ju.f[1][1] = f0, ju.f[1][2] = f1;
        ru.x = 2, ru.y = 2, ru.f[1][1] = 0, ru.f[1][2] = b, ru.f[2][1] = 1, ru.f[2][2] = a;
        quicksort(n - 1);
        printf("%0.lf\n", ju.f[1][2]);
}

int main() {
        work();
        return 0;
}
