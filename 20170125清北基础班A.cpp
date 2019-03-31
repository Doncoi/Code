//A.Flower By Doncoi
#include <cstdio>
#include <cstring>

long long N, K, P;
long long a[30], p[30];

long long quickPow(long long a, long long b, long long p){
	long long ans = 1;
	for(; b; a = (a * a) % p, b >>= 1) if(b & 1) ans = (ans * a) % p;
	return ans;
}

long long factor(long long N, long long P, long long K) {
    long long Pk, t1, t2, t3, t4;
    Pk = quickPow(P, K, 0x7fffffff);/**< Because P^K <= 100000, we can get the exact value of P^K */
    if(N < P) {
        for(t1 = t2 = 1; t1 <= N; ++ t1)
            t2 = t2 * t1 % P;
    } else {
        t2 = t3 = 1; t4 = N % Pk;
        for(t1 = 1; t1 <= t4; ++ t1)
            if(t1 % P != 0) t2 = t2 * t1 % Pk;
        for(t1 = 1; t1 < Pk;  ++ t1)
            if(t1 % P != 0) t3 = t3 * t1 % Pk;
        t3 = quickPow(t3, N/Pk, Pk);
        t2 = t2 * t3 % Pk;
        t3 = factor(N / P, P, K);
        t2 = t2 * t3 % Pk;
    }
    
    return t2;
}

long long C(long long N, long long K, long long P) {
    int i, c = 0;
    long long t1, t2, t3, pa, ans;
    t1 = P;
    for(i = 2; i * i <= t1; ++ i) if(t1 % i == 0)
        for(p[++ c] = i; t1%i == 0; t1/=i, ++ a[c]);
    if(t1 > 1) p[++ c] = t1, a[c] = 1;
    ans = 0;
    for(i = 1; i <= c; ++ i) {
        pa = quickPow(p[i], a[i], 0x7fffffff);
        t1 = factor(N, p[i], a[i]);
        t2 = factor(K, p[i], a[i]);
        t3 = factor(N-K,p[i],a[i]);
        t2 = t2*t3%pa;
        t2 = quickPow(t2, pa/p[i]*(p[i]-1)-1, pa); /**< Eular's Theorem */
        t1 = t1*t2%pa;
        t3 = 0;
        for(t2 = p[i]; t2 <= N; t2 *= p[i]) 
        	t3 += N / t2;
        for(t2 = p[i]; t2 <= K; t2 *= p[i]) 
        	t3 -= K / t2;
        for(t2 = p[i]; t2 <= N - K; t2 *= p[i]) 
        	t3 -= (N - K) / t2;
        t2 = quickPow(p[i], t3, pa);
        t1 = t1 * t2 % pa;
        t2 = quickPow(P / pa % pa, pa / p[i] * (p[i] - 1) - 1, pa);
        t2 = P / pa * t2 % P;
        t1 = t1 * t2 % P;
        ans = (ans + t1) % P;
    }

    return ans;
}

int main() {
	freopen("flower.in", r, stdin);
	freopen("flower.out", w, stdout);
    scanf("%I64d%I64d%I64d", &N, &K, &P);
    printf("%I64d\n", C(N, K, P));
    fclose(stdin);
    fclose(stdout);
}