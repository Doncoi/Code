#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <malloc.h>
using namespace std;
typedef long long ll;
#define maxn 100000

struct Hash {
    int a, b, next;
} hash[2 * maxn];

int flag[maxn];
int top, idx;

void ins(int a, int b) {
    int k = b & maxn;
    if(flag[k] != idx) {
        flag[k] = idx;
        hash[k].next = -1;
        hash[k].a = a;
        hash[k].b = b;
        return;
    }
    while(hash[k].next != -1) {
        if(hash[k].b == b) return;
        k = hash[k].next;
    }
    hash[k].next = ++ top;
    hash[top].next = -1;
    hash[top].a = a;
    hash[top].b = b;
}

int find(int b) {
    int k = b & maxn;
    if(flag[k] != idx) return -1;
    while(k != -1) {
        if(hash[k].b == b) return hash[k].a;
        k = hash[k].next;
    }
    return -1;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int exgcd(int a, int b, int &x, int &y) {
    int t, d;
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    d = exgcd(b, a % b, x, y);
    t = x, x = y, y = t - a / b * y;
    return d;
}

int inval(int a, int b, int n) {
    int x, y, e;
    exgcd(a, n, x, y);
    e = (long long)x * b % n;
    return e < 0 ? e + n : e;
}

int pow_mod(long long a, int b, int c) {
    long long ret = 1 % c;
    a %= c;
    while(b) {
        if(b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ret;
}

int BabyStep(int A, int B, int C) {
    top = maxn;
    ++ idx;
    long long buf = 1 % C, D = buf, K;
    int i, d = 0, tmp;
    for(i = 0; i <= 100; buf = buf * A % C, ++ i)
        if(buf == B) return i;
    while((tmp = gcd(A,C)) != 1) {
        if(B % tmp) return -1;
        ++ d;
        C /= tmp;
        B /= tmp;
        D = D * A / tmp % C;
    }
    int M = (int)ceil(sqrt((double)C));
    for(buf = 1 % C, i = 0; i <= M; buf = buf * A % C, ++ i)
        ins(i, buf);
    for(i = 0, K = pow_mod((long long)A, M, C); i <= M; D = D * K % C, ++ i) {
        tmp = inval((int)D, B, C);
        int w;
        if(tmp >= 0 && (w = find(tmp)) != -1)
            return i * M + w + d;
    }
    return -1;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0); 
    int A, B, C;
    while(cin >> A >> C >> B, A || B || C) {
        B %= C;
        int tmp = BabyStep(A, B, C);
        if(tmp < 0) puts("No Solution");
        else cout << tmp << endl;
    }
    return 0;
}
