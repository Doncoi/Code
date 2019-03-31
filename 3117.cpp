#include <stdio.h>
#include <string.h> 
int main() {
	char s1[505], s2[505];
	int i, j, len, l1, l2, a[505], b[505], product[1010];
	scanf("%s%s", s1, s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	memset(product, 0, sizeof(product));
	for(i = 1;i <= l1;i ++) 
		a[i] = s1[l1 - i] - 48;
	for(i = 1;i <= l2;i ++) 
		b[i] = s2[l2 - i] - 48;
	for(i = 1;i <= l2;i ++)
		for(j = 1;j <= l1;j ++)
			product[i + j - 1] += a[j] * b[i];
	for(i = 1;i < 1010;i ++)
		if(product[i] > 9) {
			product[i + 1] += product[i] / 10;
			product[i] %= 10;
		}
	for(i = 1009;i >= 1;i --)
		if(product[i]) {
			len = i;
			break;
		}
	for(i = len;i >= 1;i --)
		printf("%d", product[i]);
	return 0; 
}

