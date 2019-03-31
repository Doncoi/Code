#include <cstdio>
#include <cstring>
#include <iostream> 

int type;
int time[4];

void putin() {
	scanf("%d",&type);
	char c;
    std :: cin >> c; time[1] = c - '0';
    std :: cin >> c; time[2] = c - '0';
    getchar();
    std :: cin >> c; time[3] = c - '0';
    std :: cin >> c; time[4] = c - '0';
}

void work12() {
	int hour = 10 * time[1] + time[2];
	int minu = 10 * time[3] + time[4];
	if(hour > 12) time[1] = 0;
	if(hour == 0) time[2] = 1;
	if(minu > 59) time[3] = 0;
	printf("%d%d:%d%d",time[1],time[2],time[3],time[4]);
}

void work24() {
	int hour = 10 * time[1] + time[2];
	int minu = 10 * time[3] + time[4];
	if(hour > 23) time[1] = 0;
	if(minu > 59) time[3] = 0;
	printf("%d%d:%d%d",time[1],time[2],time[3],time[4]);
}

int main() {
	putin();
    if(type == 12) work12();
	else work24(); 
}
