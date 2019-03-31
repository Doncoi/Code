#include <bits/stdc++.h>
const int INF = 0x7fffffff;
const int MAXN = 100001;

inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') {res = res*10 + ch-'0'; ch = getchar();}
    return (res * flag);
}

struct splay{
	int root, cur;
	int ch[MAXN][2], father[MAXN];
	int size[MAXN], cnt[MAXN], key[MAXN];

	inline void update(int x) {
		size[x] = cnt[x] + size[ch[x][0]] + size[ch[x][1]];
	}

	void rotate(int x){
		int y = father[x], k = ch[y][0] == x;

		ch[y][!k] = ch[x][k], father[ch[x][k]] = y;
		father[x] = father[y], ch[father[y]][ch[father[y]][1] == y] = x;
		father[y] = x, ch[x][k] = y;
		update(y);
	}

	void spaly(int x, int g){
		for( ; father[x] != g; rotate(x))
			if (father[father[x]] != g)
				rotate((ch[father[x]][1] == x) ^ (ch[father[father[x]]][1] == father[x]) 
					   ? x : father[x]);
		update(x); if(!g) root = x;
	}

	int newnode(int f, int k, int v){
		father[++ cur] = f;
		ch[f][k] = cur;
		key[cur] = v;
		size[cur] = cnt[cur] = 1;
		return cur;                                          
	}

	int insert(int x) {
		int now = root;
		while(ch[now][x > key[now]] && key[now] != x)
			now = ch[now][x>key[now]];
		int w = now;
		if (x == key[now]) cnt[now] ++;
		else newnode(now, x > key[now], x), w = cur;
		spaly(w, 0);
		return w;
	}

	void delp(int x) {
		spaly(x, 0);
		int now = ch[x][1];
		if (!now){
			father[ch[x][0]] = 0;
			root = ch[x][0];
			return;
		}
		while(ch[now][0])
			now = ch[now][0];
		spaly(now,x), father[now] = 0;
		father[ch[x][0]] = now, ch[now][0] = ch[x][0];
		update(now), root = now;
	}

	void del(int x) {
		int now = root;
		while(key[now] != x)
			now = ch[now][x > key[now]];
		if (cnt[now] > 1)
			cnt[now] --, spaly(now , 0);
		else delp(now);                                                 
	}

	int kth(int x, int k) {
		int w = size[ch[x][0]];
		if (k <= w) return kth(ch[x][0], k);
		else if (k <= w + cnt[x]) return x;
		else return kth(ch[x][1], k - w - cnt[x]);
	}

	int kth(int k) {
		if (k > size[root]) return INF;
		if (k < 1) return -INF; 
		int res = kth(root,k);
		spaly(res, 0);
		return key[res];
	}

	int rank(int x) {
		int now = root, ans = 1;
		while(ch[now][x > key[now]]) {
			if (x > key[now])
				ans += size[ch[now][0]] + cnt[now];
			now = ch[now][x > key[now]];                
		}
		if (x > key[now])
			ans += size[ch[now][0]] + cnt[now];
		spaly(now, 0);
		return ans;
	}

	int pre(int x) {
		int now = root, ans = -INF;
		while(ch[now][x > key[now]]) {
			if (key[now] < x && key[now] > ans)
				ans = key[now];
			now = ch[now][x > key[now]];
		}
		if (key[now] < x && key[now] > ans)
			ans = key[now];
		spaly(now, 0);
		return ans;
	}

	int suc(int x){
		int now = root, ans = INF;
		while(ch[now][x >= key[now]]) {
			if (key[now] > x && key[now] < ans)
				ans = key[now];
			now = ch[now][x >= key[now]];
		}
		if (key[now] > x && key[now] < ans)
			ans = key[now];
		spaly(now, 0);
		return ans;
	}
} splay;

int main(){
	freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
	int n = read();
	while(n--) {
		int opt = read(), x = read();
		switch (opt){
			case 1: splay.insert(x); break;
			case 2: splay.del(x); break;
			case 3: printf("%d\n", splay.rank(x)); break;
			case 4: printf("%d\n", splay.kth(x)); break;
			case 5: printf("%d\n", splay.pre(x)); break;
			case 6: printf("%d\n", splay.suc(x)); break;
		}
		
		//printf("\n\n--------------------------------------------\nroot : %d\n", splay.root);for(int i = 0; i <= splay.cur; ++ i) {printf("ID : %d\n", i);printf("fatherther : %d    lc : %d    rc : %d\n", splay.father[i], splay.ch[i][0], splay.ch[i][1]);printf("key : %d    size : %d    cnt : %d\n", splay.key[i], splay.size[i], splay.cnt[i]);}printf("--------------------------------------------\n\n");
	}
}
