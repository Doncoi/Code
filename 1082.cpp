#include<cstdio>
#define left l,m,rt<<1
#define right m+1,r,rt<<1|1
#define int_ long long 

using namespace std;

const int maxn=200001;

int_ res[maxn << 2],mark[maxn << 2];

int_ read(int_ &x){
	char c = getchar(),last; x = 0;
	while(c < '0' || c > '9') last = c,c = getchar();
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0',c = getchar();
	if(last == '-') x = -x;
	return x;
}

void push_up(int_ rt){
	res[rt]=res[rt << 1]+res[rt << 1 | 1];
}

void push_down(int_ rt,int_ len ){
	if(mark[rt]) {
		mark[rt << 1] += mark[rt];
		mark[rt << 1|1] += mark[rt];
		res[rt << 1] += (len - (len >> 1)) * mark[rt];
		res[rt << 1|1] += (len >> 1) * mark[rt];
		mark[rt] = 0;
    }
}

void build(int_ l,int_ r,int_ rt) {
	if(l == r) {
		read(res[rt]);
		return ;
	}
	int_ m = (l + r) >> 1;
	build(left);
	build(right);
	push_up(rt);
}

void update(int_ L,int_ R,int_ add,int_ l,int_ r,int_ rt){
	if(L <= l && r <= R){
		mark[rt] += add;
		res[rt] += (add * (r - l + 1));
		return;
	}
	push_down(rt,r - l + 1);
	int_ m = (l + r) >> 1;
	if(L <= m) update(L,R,add,left);
	if(R > m) update(L,R,add,right);
	push_up(rt);
	return;
}

int_ enquiry(int_ L,int_ R,int_ l,int_ r,int_ rt){
	if(L <= l && r <= R)return res[rt];
	push_down(rt,r - l + 1);
	int_ m = (l + r) >> 1, ret = 0;
	if(L <= m)ret += enquiry(L,R,left);
	if(R > m)ret += enquiry(L,R,right);
	return ret;
}
int main() {
	int_ n,q;
	read(n);
	build(1,n,1);
	read(q);
	int_ x,y,z,w;
	for(int i = 1;i <= q;i ++) {
		read(x);
		if(x == 1){
		read(y); read(z); read(w);
		update(y,z,w,1,n,1);
	}
	else {
		read(y); read(z);
		printf("%lld\n",enquiry(y,z,1,n,1));
	}
}
return 0;
}
