#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
struct Node{  
    Node *ch[2];  
    int r, v, s, num;  
    bool operator < (const Node& rhs) const{  
        return r < rhs.r;  
    }  
    int cmp(int x){  
        if(x < v) return 0;  
        if(x == v) return -1;  
        return 1;  
    }  
    int cmp1(int x){  
        int k = num;  
        if(ch[0]) k += ch[0] -> s;  
        if(k - num + 1 <= x && x <= k) return -1;  
        if(x <= k - num) return 0;  
        return 1;   
    }  
    void maintain(){  
        s = num;  
        if(ch[0]) s += ch[0] -> s;  
        if(ch[1]) s += ch[1] -> s;  
    }  
};  
struct treap{  
    Node ft[5000000];  
    int tot;  
    Node *root;  
    void rotate(Node* &o, int d){  
        Node* k = o -> ch[d ^ 1];  
        o -> ch[d ^ 1] = k -> ch[d];  
        k -> ch[d] = o;  
        o -> maintain();  
        k -> maintain();  
        o = k;   
    }  
    void insert(Node* &o, int x){  
        if(o == NULL){  
            o = &ft[tot ++];  
            o -> ch[0] = o -> ch[1] = NULL;  
            o -> v = x;  
            o -> r = rand();  
            o -> num = o -> s = 1;  
            return;   
        }  
        int d = o -> cmp(x);  
        if(d == -1) o -> num ++;  
        else {  
            insert(o -> ch[d], x);  
            if(o -> ch[d] > o) rotate(o, d ^ 1);  
        }  
        o -> maintain();   
    }  
    void remove(Node* &o, int x){  
        int d = o -> cmp(x);  
        if(d == -1){  
            if(o -> num > 1) o -> num --;  
            else if(o -> ch[0] && o -> ch[1]) {  
                int d2 = 0;  
                if(o -> ch[0] > o -> ch[1]) d2 = 1;  
                rotate(o, d2);  
                remove(o -> ch[d2], x);  
            }  
            else {  
                if(o -> ch[0]){  
                    o = o -> ch[0];  
                }  
                else o = o -> ch[1];  
            }  
        }  
        else remove(o -> ch[d], x);  
        if(o) o -> maintain();  
    }  
    int find(Node* &o, int x){  
        if(o == NULL) return 0;  
        int d = o -> cmp(x);  
        if(d == -1) return o -> num;  
        return find(o -> ch[d], x);  
    }  
    int less_k(Node* &o, int k){  
        if(o == NULL) return 0;  
        int d = o -> cmp(k);  
        int yy = o -> num;  
        if(o -> ch[0]) yy += o -> ch[0] -> s;    
        if(d == -1) return yy - o -> num;  
        else if(d == 0) return less_k(o -> ch[0], k);  
        else return less_k(o -> ch[1], k) + yy;   
    }  
    int kth(Node* &o, int k){  
        int d = o -> cmp1(k);  
        int yy = o -> num;  
        if(o -> ch[0]) yy += o -> ch[0] -> s;  
        if(d == -1) return o -> v;  
        if(d == 0) return kth(o -> ch[0], k);  
        return kth(o -> ch[1], k - yy);  
    }  
} wt;  
int main(){  
    int n;  
    scanf("%d", &n);  
    for(int i = 1; i <= n; i ++){  
        int op, x;  
        scanf("%d%d", &op, &x);  
        if(op == 1){  
            wt.insert(wt.root, x);  
        }  
        else if(op == 2){  
            wt.remove(wt.root, x);  
        }  
        else if(op == 3){  
            printf("%d\n", wt.less_k(wt.root, x) + 1);  
        }  
        else if(op == 4){  
            printf("%d\n", wt.kth(wt.root, x));  
        }  
        else if(op == 5){  
            int yy = wt.less_k(wt.root, x);  
            printf("%d\n", wt.kth(wt.root, yy));  
        }  
        else{  
            int yy = wt.less_k(wt.root, x);  
            yy += wt.find(wt.root, x) + 1;  
            printf("%d\n", wt.kth(wt.root, yy));  
        }  
    }  
    return 0;  
}   


