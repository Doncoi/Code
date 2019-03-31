#include <iostream>
#include <algorithm>
#include <cstdio>

const int MAXN = 1e6 + 9;
int n, p[MAXN];

struct node{
    int from, next;
    int belong;
    node () : belong(0){}
}nodes[MAXN];

struct loop{
    int first, num;
    bool godie;
    loop () : num(0), godie(false) {}
}loops[MAXN];
inline int _getchar() {
    int x = 0; char ch = getchar();
    while (ch > '9' || ch < '0') ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x;
}

inline void up (int i, int j) {
    loops[j].godie = loops[i].godie = true;
    int x = loops[i].first, y = loops[j].first;
    for (int k = 1; k <= loops[j].num + loops[i].num; k++) {
        if (k % 2){
            p[x] = y;
            x = nodes[x].next;
        } else {
            p[y] = x;
            y = nodes[y].next;
        }
    }
}

inline void up (int i, loop j) {
    j.godie = loops[i].godie = true;
    int x = loops[i].first, y = j.first;
    for (int k = 1; k <= loops[i].num; k++) {//注意 终止条件
        if (k % 2){
            p[x] = y;
            x = nodes[x].next;
        } else {
            p[y] = x;
            y = nodes[y].next;
        }
    }
}
int main () {
    n = _getchar();
    for (int i = 1; i <= n; i++) {
        nodes[i].next = _getchar();
        nodes[nodes[i].next].from = i;
    }
    //建图
    int loopnum = 0;
    for (int i = 1; i <= n; i++) if (!nodes[i].belong) {
        int x = i;
        ++loopnum;
        loops[loopnum].first = x;
        while (true) {
            nodes[x].belong = loopnum;
            loops[loopnum].num++;
            x = nodes[x].next;
            if (x == loops[loopnum].first) break;
        }
    }

    for (int i = 1; i <= loopnum; i++) if (!loops[i].godie) {
        //自环
        if (loops[i].num == 1) {
            p[loops[i].first] = loops[i].first;
            loops[i].godie = true;
            continue;
        }
        //奇环
        if (loops[i].num % 2) {
            loop k;
            int num = loops[i].num;
            k.num = num / 2;
            for (int j = 1, x = loops[i].first; j <= num; j++, x = nodes[x].next) {
                if (j == num / 2 + 2) {
                    nodes[nodes[x].from].next = loops[i].first;
                    k.first = x;
                }
            }
            up(i, k);
            loops[i].godie = true;
        } else {
        //偶环
            for (int j = i + 1; j <= loopnum; j++) {
                if (loops[j].num == loops[i].num && !loops[j].godie) {
                    up(i, j);
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= loopnum; i++) {
        if (!loops[i].godie) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) std :: cout << p[i] << " ";
    return 0;
}

