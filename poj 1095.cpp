#include <cstdio>
#include <algorithm>

int mp,s,t;
int dis = 0;

int main() {
	scanf("%d%d%d",&mp,&s,&t);
	while(mp >= 10) {
		dis += 60; mp -= 10; t--;
	}
	while(t >= 4) {
		t--;
		mp += 4;
		while(mp >= 10) {
		    dis += 60; mp -= 10; t--;
	    }
	}
    printf("%d %d %d",mp,s - dis,t);
}
