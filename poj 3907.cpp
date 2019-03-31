#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXN 10005

int n;

struct Node {
    double x, y;
} node[MAXN];

double solve(struct Node a, struct Node b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
   
    while(std :: cin >> n && n) {
        double sum = 0;
        for(int i = 0; i < n; ++ i ) {
           std :: cin >> node[i].x >> node[i].y;
        }
        for(int i = 1; i <= n; ++ i) {
            sum += solve(node[i - 1], node[i % n]);
        }
        std :: cout << (int)fabs(sum) / 2 << std :: endl;
    }
}
