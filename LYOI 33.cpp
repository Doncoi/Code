#include <cstdio>

int solve(const int a, const int b) {
    return !b ? 0 : solve(b, a % b) + a / b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", solve(n, m));
    return 0;
}
