#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_long 10000

int n, m, k;
int up[max_long], down[max_long];
int f[2][1005];
bool reach[2][1005];

struct Conduit {
	int p, l, h;
} conduit[max_long];

inline bool cmp(const Conduit &a, const Conduit &b) {
	return a.p < b.p;
}

void hacking_to_the_sky() {
	int pre_conduit = 1;
	bool reach_end = 0;
    int ans = n;

    for(int i = 1;i <= n;i ++) {
    	int pre_position = i & 1;
    	bool flag = 0;
    	if(i == conduit[pre_conduit].p)    //�жϸ�����û�йܵ�
    		 flag = 1;          
    	   


    	for(int j = 0;j <= m;j ++) {

    	    if(flag) {				                    //�����ҿɲ���ײ��conduit
    	    	if(j <= conduit[pre_conduit].l || j >= conduit[pre_conduit].h)
    	    	reach[pre_position][j] = 0;
    	        continue;
    	    }
    		
    		if(j + down[(i - 1) & 1] <= m) 				//�������ж��ܷ�ͨ���½����������
    			if(reach[ (i - 1) & 1 ][ j + down[i - 1] ]) 
    				f[pre_position][j] = f[ (i - 1) & 1 ][j + down[i - 1]];  

			int pre_highth = j;                         //���ڶ������ͨ����Ծ���ﵱǰ���λ�ã�����Ҫȡ����������Сֵ 
			int minn = n;
			while(pre_highth >= up[i - 1]) {
				pre_highth -= up[i - 1];
				if(reach[ (i - 1) & 1 ][pre_highth])
					minn = std :: min (f[ (i - 1) & 1 ][pre_highth] + (j - pre_highth) / up[i - 1], minn);
			}    

			if(minn = m && f[pre_position][j] == -1) {
				reach[pre_position][j] = 0;
				continue;
			}		

			if(f[pre_position][j] == -1) f[pre_position][j] = minn;
			else f[pre_position][j] = std :: min (minn, f[pre_position][j]);
    	}

    	if(flag) pre_conduit++;   //������һ���ܵ���λ��
    	if(i == n) {
   			for(int j = 0;j <= m;j ++) 
    			if(reach[pre_position][j]) {
    				reach_end = 1;
    				ans = std :: min(ans, f[pre_position][j]);
    			}
    	}

    	printf("%d\n", i);
    	for(int j = m;j >= 0;j --)
    		printf("%d  ", f[i & 1][j]);
    	printf("\n"); 
    }
    

    if(reach_end) 
    	printf("1\n%d\n", ans);
    else 
    	printf("0\n");
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0;i < n;i ++) 
		scanf("%d%d", &up[i], &down[i]);
	for(int i = 1;i <= k;i ++)
		scanf("%d%d%d", &conduit[i].p, &conduit[i].l, &conduit[i].h);
    
    //���ڿ��Դ�����Ե�������������ʱ߽�Ϊf[0][i] = 0,f[1][i]��Ҫ���д�0��1�����½����������ͨ���ܵ������;
    memset(f, -1, sizeof(f));
    memset(reach, 1, sizeof(reach));
    std :: sort(conduit + 1, conduit + k + 1, cmp);
    for(int i = 0;i <= m;i ++) {
    	if(m - i < down[0]) {
    		if(i < up[0]) reach[1][i] = 0;
    		f[1][i] = 1;
    	}
    	else f[1][i] = 0;
    }

    /*for(int j = m;j >= 0;j --)
    	printf("%d  ", f[1 & 1][j]);
    printf("\n"); */

    hacking_to_the_sky();
}
