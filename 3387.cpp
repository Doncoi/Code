#include <cstdio>
#include <cstring>

int m;

int main() {
	scanf("%d", &m);
	if(m == 1) printf("C");
	else if(m == 2) printf("O");
	else if(m == 3) printf("D");
	else if(m == 4) printf("E");
	else if(m == 5) printf("V");
	else printf("S");
}