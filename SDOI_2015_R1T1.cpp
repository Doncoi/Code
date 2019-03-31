#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 15
#define MAXM 10005

bool ch[MAXM];
//powԤ����2��ָ���ݣ�facԤ����׳ˣ�len�������г���
int a[MAXM], pow[MAXN], fac[MAXN], n, len;
long long ans;

//pre����ǰ���������±꣬len...����֪�ĺϷ��������еĳ���
inline void DFS(int pre, int len_of_operator_queue) {
	//������У����ڲ��������ڲ�����˳��Ӱ����Ч�������Դ𰸼��ϲ������гɶ��Ľ׳�
	if(pre == n) {ans += fac[len_of_operator_queue]; return;}
	int num_of_illegal_pos = 0, xp = -1, yp = -1;
	for(int i = 0; i < len / pow[pre + 1]; ++ i) {
		int fi = i * pow[pre + 1] + 1, fx = fi + pow[pre];
		if(a[fi + pow[pre] - 1] - a[fx] != -1) {
			++ num_of_illegal_pos;
			if(xp = -1) xp = i; else yp = i;
		}
	}
	//��Ϊÿ��ֻ�ܽ����������䣬���Բ��Ϸ����������ڵ���3ʱ���޽���
	if(num_of_illegal_pos > 2) return;
	//û�зǷ�λ�ã�ֱ�ӵݹ����
	if(!num_of_illegal_pos) DFS(pre + 1, len_of_operator_queue);
 	else {
 		//ֻ��һ���Ƿ�λ�ã�����
 		if(num_of_illegal_pos == 1) {
 			int fi = xp * pow[pre + 1] + 1, fx = fi + pow[pre];
 			for(int j = 1; j <= pow[pre]; ++ j) 
 				std :: swap(a[fi + j - 1], a[fx + j - 1]);
 			if(a[fi + pow[pre] - 1] - a[fx] == -1) 
 				DFS(pre + 1, len_of_operator_queue + 1);
 			for(int j = 1; j <= pow[pre]; ++ j) 
 				std :: swap(a[fi + j - 1], a[fx + j - 1]);
 		} else {
 			int p[4][2];
 			p[0][0] = xp * pow[pre + 1], p[1][0] = p[0][0] + pow[pre];
 			p[2][0] = yp * pow[pre + 1] + 1, p[3][0] = p[2][0] + pow[pre];
 			for(int i = 0; i < 2; ++ i) p[i][1] = p[0][0];
 			for(int i = 2; i < 4; ++ i) p[i][1] = p[2][0];
 			for(int i = 0; i < 2; ++ i) 
 				for(int j = 2; j < 4; ++ j) {
 					int fi = p[i][0], fx = p[j][0];
 					for(int k = 1; k <= pow[pre]; ++ k) 
 						std :: swap(a[fi + k - 1], a[fx + k - 1]);
 					if(a[p[i][1] + pow[pre] - 1] - a[p[i][1] + pow[pre]] == -1
 				    && a[p[j][1] + pow[pre] - 1] - a[p[j][1] + pow[pre]] == -1)
 						DFS(pre + 1, len_of_operator_queue + 1);
 					for(int k = 1; k <= pow[pre]; ++ k) 
 						std :: swap(a[fi + k - 1], a[fx + k - 1]);
 				}
  		}
 	}
}

inline int read() {
	char ch = getchar(); int res = 0, flag = 1;
	while(ch < '0' || ch > '9') {if(ch == '-') flag = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {res = res  * 10 + ch - '0'; ch = getchar();}
	return (res * flag);
}

int main() {
	n = read();
	pow[0] = fac[0] = 1;
	for(int i = 1; i <= n; ++ i)
		pow[i] = pow[i - 1] * 2, fac[i] = fac[i - 1] * i;
	len = pow[n];
	for(int i = 1; i <= len; ++ i) a[i] = read();
	DFS(0, 0);
	printf("%I64d\n", ans);
	return 0;
}
