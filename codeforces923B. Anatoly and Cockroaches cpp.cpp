#include <cstdio>

int n,ans;
int red = 0,black = 0;

void redputin() {                    //ÆæÊıºì£¬Å¼ÊıºÚ
	for(int i = 2;i <= n;i ++) {
		char ch = getchar();
		if(i % 2 && ch == 'b') black++;
		else if (!i % 2 && ch == 'r') red ++; 
	}
}

void blackputin() {              //ÆæÊıºÚ£¬Å¼Êıºì
	for(int i = 2;i <= n;i ++) {
		char ch = getchar();
		if(i % 2 && ch == 'r') red++;
		else if (!i % 2 && ch == 'b') black++; 
	}
}

int main() {
	scanf("%d",&n);
	char ch = getchar();
	ch = getchar(); 
	if(ch == 'r') redputin();
	else if(ch == 'b') blackputin();
	ans = red > black ? red : black;
	ans = ans >= n/2 ? (n - ans) : ans;
	printf("%d  %d\n",red,black);
	printf("%d",ans);
	return 0;
}
