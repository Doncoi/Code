#include <cstdio>

int pre;
int money,pack;

int work() {
	for(int i = 1;i <= 12;i ++) {
		scanf("%d",&pre);
		money += 300; money -= pre;
		if(money < 0) return i * -1;
		else pack += money/100,money %= 100;
	}
	pack = pack * 120;
	money += pack; 
	return money;
}

int main() {	
	printf("%d",work());
}
