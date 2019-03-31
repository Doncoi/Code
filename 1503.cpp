#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#define Nmax 1000005

using namespace std;

long long edge[Nmax] = { 0 };
long long path1[Nmax] = { 0 }, path2[Nmax] = {0};
long long N;

int main() {
	scanf("%lld", &N); 
	long long i, j, k; 
	long long *p, *q, *r, *s; 
	for (i = 1; i <= N - 1; i++) {
		scanf("%lld %lld", &j, &k);
		edge[k] = j;
	}
	scanf("%lld %lld", &j, &k);
	path1[0] = path2[0] = -1;
	path1[1] = j; 	path2[1] = k;
	for (j = 1; path1[j] != 0; j++)
		path1[j+1] = edge[path1[j]];
	for (j = 1; path2[j] != 0; j++)
		path2[j + 1] = edge[path2[j]];
	p = find(path1, path1 + N, 0);	q = find(path2, path2 + N, 0);
	for (r = q, s = p; *r == *s&&r != path2 && s != path1; r--, s--);
	printf("%lld\n", *(r + 1));
	return 0;
}
