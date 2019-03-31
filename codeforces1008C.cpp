#include <cstdio>
#include <algorithm>
#define maxn 100005

struct Node {
    int x,y;
    int time;
} node[maxn];

int N,M,k;
int n = 0,m = 0,T = 0;
int dx = 1,dy = 1;

bool judge() {
	if(n == N && m == 0) return false;
	else if(n == N && m == M) return false;
	else if(n == 0 && m == 0) return false;
	else if(n == 0 && m == M) return false;
	else return true;
}

int main() {
	scanf("%d%d%d",&N,&M,&k);
	for(int i = 1;i <= N;i ++) {
        scanf("%d%d",&node[i].x,&node[i].y);
        node[i].time = -1;
	}

	while(judge()) {
        n += dx; m += dy; T++;
        if(n == N || n == 0) dy = - dy;
        else if(m == 0 || m == M) dx = - dx;
        else for(int i = 1;i <= k;i ++) 
                 if(node[i].time < 0)
                 	if(node[i].x == n && node[i].y == m) node[i].time = T;
	}

	for(int i = 1;i <= k;i ++) printf("%d\n",node[i].time);
}
