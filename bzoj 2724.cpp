#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 40005
#define MAXM 205
#define INF 0x3f3f3f3f

//n记录元素总数，m记录元素种类，Q记录询问数量，l，r，ans
int n, m, Q, l, r, ans;
//a[]记录离散化后的下标，b[]辅助离散化的进行，sum[]作为临时数组，在预处理时记录某个块内每个元素出现的次数
int a[MAXN], b[MAXN], sum[MAXN];
//s记录块的总数， S记录每个块的大小，bl[i]记录第i各块的左端点，br[i]记录第i个块的右端点
//f[i][j]记录第i到j个块间的众数，cnt[i][j]记录元素i在前j个块中出现的次数
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
    int k, cur, maxv, h, t, c;                     //cur与maxv辅助记录众数和其出现次数
    for(int i = 1; i <= s; ++ i) {                 //预处理各个区间的众数
        k = bl[i], cur = INF, maxv = -INF, t, c;   //k记录当前块的左端点

        for(int j = k; j < n; ++ j) {              //从左端点开始
            sum[a[j]] = 0;                         //元素j出现的次数置空，没出现的元素的储存单元不需要更改
        }

        for(int j = i; j <= s; ++ j) {             //从当前块开始处理到最后一个块
            t = br[j];                             //记录枚举块的右端点
            while(k <= t) {                        //从块i的左端点到块j的右端点扫描，k为当前元素
                c = ++ sum[a[k]];                  //当前元素出现次数加一
                if(c > maxv) maxv = c, cur = a[k]; //记录最大值及已知众数
                else if(c == maxv && a[k] > cur) cur = a[k];
                ++ k;
            }

            f[i][j] = cur;                         //块i到块j间的众数为cur
        }
    }

    memset(sum, 0, sizeof(sum));              //处理第j个元素在前i个块里出现的次数
    for(int i = 1; i <= s; ++ i) {            //枚举块
        for(int j = 0; j < m; ++ j) {         //枚举元素种类
            cnt[j][i] = cnt[j][i - 1];        //先将该元素在前i - 1个块中出现的次数继承
        }

        h = bl[i], t = br[i];                 //当前块的左右端点

        while(h <= t) {                       //单独记录该元素在当前块的出现次数，并加和
            cnt[a[h]][i] = ++ sum[a[h]];      //得到了该元素在前i个区间内出现的次数
            ++ h;
        }
    }

    return;
}

inline int query(const int &l, const int &r) {
    int maxv = -INF, res = INF, c;
    if(r - l < 2 * S) {                       //询问区间包含最多一个块
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

    int L = l / S + 1, R = r / S + 1, st, ed;       //L是查询区间包含的最左侧的块的编号，R为最右端的块的编号
    if(l == bl[L]) -- L;            //处理恰好包含端点的情况
    if(r == br[R]) ++ R;

    //res储存的是众数离散化后的对应下标
    res = f[L + 1][R - 1], maxv = cnt[res][R - 1] - cnt[res][L];  //先将L到R块内的已知众数记为答案，通过差分处理出它出现的次数，并通过maxv记录
    ed = br[L], st =bl[R];          //ed记录左侧没有被完整包含的区间的右端点，st记录右侧没有被完整包含的区间的左端点
    //l --- ed ----------完整的块------------st --- r
    for(int i = l; i <= ed; ++ i) {      //暴力处理左侧区间
        if(!visited[a[i]]) visited[a[i]] = true, sum[a[i]] = 1;
        else ++ sum[a[i]];
    }

    for(int i = st; i <= r; ++ i) {      //暴力处理右侧区间
        if(!visited[a[i]]) visited[a[i]] = true, sum[a[i]] = 1;
        else ++ sum[a[i]];
    }

    for(int i = l; i <= ed; ++ i) {      //由左区间更新答案
        if(visited[a[i]]) {
            c = cnt[a[i]][R - 1] - cnt[a[i]][L];
            c += sum[a[i]];
            if(c > maxv) maxv = c, res = a[i];
            else if(c == maxv && a[i] < res) res = a[i];
            visited[a[i]] = false; 
        }
    }

    for(int i = st; i <= r; ++ i) {      //由右区间更新答案
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
    std :: sort(b, b + n);                          //对临时数组b[i]排序
    m = std :: unique(b, b + n) - b;                //计算元素种类
    for(int i = 0; i < n; ++ i) {                   //a[i]记录在已排序去重的b[i]中小于a[i]的第一个元素位置，
        a[i] = std :: lower_bound(b, b + m, a[i]) - b;    //即每一个元素被离散化后的下标
    }

    for(int i = 0; i < n; ++ i) {                   //处理每个块的左端点和右端点
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
