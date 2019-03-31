#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 40005
#define MAXM 205
#define INF 0x3f3f3f3f

//n��¼Ԫ��������m��¼Ԫ�����࣬Q��¼ѯ��������l��r��ans
int n, m, Q, l, r, ans;
//a[]��¼��ɢ������±꣬b[]������ɢ���Ľ��У�sum[]��Ϊ��ʱ���飬��Ԥ����ʱ��¼ĳ������ÿ��Ԫ�س��ֵĴ���
int a[MAXN], b[MAXN], sum[MAXN];
//s��¼��������� S��¼ÿ����Ĵ�С��bl[i]��¼��i�������˵㣬br[i]��¼��i������Ҷ˵�
//f[i][j]��¼��i��j������������cnt[i][j]��¼Ԫ��i��ǰj�����г��ֵĴ���
int s, S, bl[MAXM], br[MAXN], f[MAXM][MAXM], cnt[MAXN][MAXM];  
//visited[]
bool visited[MAXN]; 

inline int read() {
    static char ch;
    while((ch = getchar()) < '0' || ch > '9');
    int res = ch - 48;
    while((ch = getchar()) >= '0' || ch <= '9') {
        res = res * 10 + ch - 48;
    }

    return res;
}

inline void init() {
    int k, cur, maxv, h, t, c;                     //cur��maxv������¼����������ִ���
    for(int i = 1; i <= s; ++ i) {                 //Ԥ����������������
        k = bl[i], cur = INF, maxv = -INF, t, c;   //k��¼��ǰ�����˵�

        for(int j = k; j < n; ++ j) {              //����˵㿪ʼ
            sum[a[j]] = 0;                         //Ԫ��j���ֵĴ����ÿգ�û���ֵ�Ԫ�صĴ��浥Ԫ����Ҫ����
        }

        for(int j = i; j <= s; ++ j) {             //�ӵ�ǰ�鿪ʼ�������һ����
            t = br[j];                             //��¼ö�ٿ���Ҷ˵�
            while(k <= t) {                        //�ӿ�i����˵㵽��j���Ҷ˵�ɨ�裬kΪ��ǰԪ��
                c = ++ sum[a[k]];                  //��ǰԪ�س��ִ�����һ
                if(c > maxv) maxv = c, cur = a[k]; //��¼���ֵ����֪����
                else if(c == maxv && a[k] > cur) cur = a[k];
                ++ k;
            }

            f[i][j] = cur;                         //��i����j�������Ϊcur
        }
    }

    memset(sum, 0, sizeof(sum));              //�����j��Ԫ����ǰi��������ֵĴ���
    for(int i = 1; i <= s; ++ i) {            //ö�ٿ�
        for(int j = 0; j < m; ++ j) {         //ö��Ԫ������
            cnt[j][i] = cnt[j][i - 1];        //�Ƚ���Ԫ����ǰi - 1�����г��ֵĴ����̳�
        }

        h = bl[i], t = br[i];                 //��ǰ������Ҷ˵�

        while(h <= t) {                       //������¼��Ԫ���ڵ�ǰ��ĳ��ִ��������Ӻ�
            cnt[a[h]][i] = ++ sum[a[h]];      //�õ��˸�Ԫ����ǰi�������ڳ��ֵĴ���
            ++ h;
        }
    }

    return;
}

inline int query(const int &l, const int &r) {
    int maxv = -INF, res = INF, c;
    if(r - l < 2 * S) {                       //ѯ������������һ����
        for(int i = l; i <= r; ++ i) {
            if(!visited[a[i]]) visited[a[i]] = true, sum[a[i]] = 1;
            else ++ sum[a[i]];
        }

        for(int i = l; i <= r; ++ i) {
            if(visited[a[i]]) {
                if(sum[a[i]] > maxv) maxv = sum[a[i]], res = a[i];
                else if(sum[a[i]] == maxv && a[i] < res) res = a[i];
                visited[a[i]] = false;
            }
        }

        return b[res];
    }

    int L = l / S + 1, R = r / S + 1, st, ed;       //L�ǲ�ѯ��������������Ŀ�ı�ţ�RΪ���Ҷ˵Ŀ�ı��
    if(l == bl[L]) -- L;            //����ǡ�ð����˵�����
    if(r == br[R]) ++ R;

    //res�������������ɢ����Ķ�Ӧ�±�
    res = f[L + 1][R - 1], maxv = cnt[res][R - 1] - cnt[res][L];  //�Ƚ�L��R���ڵ���֪������Ϊ�𰸣�ͨ����ִ���������ֵĴ�������ͨ��maxv��¼
    ed = br[L], st =bl[R];          //ed��¼���û�б�����������������Ҷ˵㣬st��¼�Ҳ�û�б������������������˵�
    //l --- ed ----------�����Ŀ�------------st --- r
    for(int i = l; i <= ed; ++ i) {      //���������������
        if(!visited[a[i]]) visited[a[i]] = true, sum[a[i]] = 1;
        else ++ sum[a[i]];
    }

    for(int i = st; i <= r; ++ i) {      //���������Ҳ�����
        if(!visited[a[i]]) visited[a[i]] = true, sum[a[i]] = 1;
        else ++ sum[a[i]];
    }

    for(int i = l; i <= ed; ++ i) {      //����������´�
        if(visited[a[i]]) {
            c = cnt[a[i]][R - 1] - cnt[a[i]][L];
            c += sum[a[i]];
            if(c > maxv) maxv = c, res = a[i];
            else if(c == maxv && a[i] < res) res = a[i];
            visited[a[i]] = false; 
        }
    }

    for(int i = st; i <= r; ++ i) {      //����������´�
        if(visited[a[i]]) {
            c = cnt[a[i]][R - 1] - cnt[a[i]][L];
            c += sum[a[i]];
            if(c > maxv) maxv = c, res = a[i];
            else if(c == maxv && a[i] < res) res = a[i];
            visited[a[i]] = false;
        }
    }

    return b[res];
}

int main() {
    n = read(); Q = read(); S = sqrt(n);

    for(int i = 0; i < n; ++ i) {
        a[i] = b[i] = read();
    }
    std :: sort(b, b + n);                          //����ʱ����b[i]����
    m = std :: unique(b, b + n) - b;                //����Ԫ������
    for(int i = 0; i < n; ++ i) {                   //a[i]��¼��������ȥ�ص�b[i]��С��a[i]�ĵ�һ��Ԫ��λ�ã�
        a[i] = std :: lower_bound(b, b + m, a[i]) - b;    //��ÿһ��Ԫ�ر���ɢ������±�
    }

    for(int i = 0; i < n; ++ i) {                   //����ÿ�������˵���Ҷ˵�
        if(i % S == 0) br[s] = i - s, bl[++ s] = i;
    }
    br[s] = n - 1, bl[s + 1] = br[s + 1] = n;
    init();

    while(Q --) {
        l = read(); r = read();
        l = (l + ans - 1) % n; r = (r + ans - 1) % n;    
        if(l > r) std :: swap(l ,r);
        printf("%d\n", ans = query(l, r));
    }

    return 0;
}
