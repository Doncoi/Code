#include <iostream>
#include <cstring>
#include <algorithm>
#define maxll 0x7fffffff
#define Maxn 100005
#define mid (this->l + this->r >> 1)
#define judgement type[1]

int n,m;
std :: string type;
int l,r;
long long w;
int a[Maxn];

struct Node{
    int l, r; // [l, r)
    Node *lc, *rc;                    //两个指向node类型的指针
    long long sum;                        
    long long lazy_add; bool sign_add;
    long long lazy_set; bool sign_set;
    long long  maxn,minn;
    
    Node(int l, int r){              
        this->l = l, this->r = r;     //this -> l == node[pre].l
        sum = lazy_add = lazy_set = 0;
        sign_add = sign_set = false;
        maxn = -1; minn = maxll;
    }
    
    void add(long long delta) {           //延迟标记，不查询不下放
        sign_add = true;
        lazy_add += delta;                
        sum += delta * (r - l);
    }

    void set(long long delta) {
        if(sign_add) {
            sign_add = false;
            lazy_add = 0;
            sign_set = true;
            lazy_set = delta;
            sum = delta * (r - l); 
        }
        else {
            sign_set = true;
            lazy_set = delta;
            sum = delta * (r - l); 
        }
    }

    void pushDown(){                     //标记下放
        if(!sign_set && sign_add){       //有add无set               
            lc->add(lazy_add);          
            rc->add(lazy_add);
            
            lazy_add = 0;
            sign_add = false;
        }
        else if(sign_set && sign_add) {   //先set后add
            lc->set(lazy_set);
            rc->set(lazy_set);

            lazy_set = 0;
            sign_set = false;

            lc->add(lazy_add);          
            rc->add(lazy_add);
            
            lazy_add = 0;
            sign_add = false;
        }
        else if(sign_set){             //只有set或先add后set
            lc->set(lazy_set);
            rc->set(lazy_set);

            lazy_set = 0;
            sign_set = false;
        }
    }

    void update(){                    //由子区间更新
        sum = lc->sum + rc->sum;     
        maxn = std :: max(std :: max(lc->sum,sum), std :: max(rc->sum,sum));
        minn = std :: min(std :: min(lc->sum,sum), std :: min(rc->sum,sum));
    }
    
    void build(){                     //构造
        if(r - l == 1){
            sum = a[l];
            maxn = a[l];
            minn = a[l];
        } 
        else{
            lc = new Node(l, mid), lc->build();
            rc = new Node(mid, r), rc->build();
            
            update();
        }
    }

    void modify_add(int l, int r, long long delta) {      //区间修改
        if(l == this->l && r == this->r) add(delta);
        else{
            if(l < mid) lc->modify_add(l, std::min(mid, r), delta);
            if(r > mid) rc->modify_add(std::max(mid, l), r, delta);
            
            update();
        }
    }

    void modify_set(int l,int r,long long delta) {
        if(l == this->l && r == this->r) set(delta);
        else{
            if(l < mid) lc->modify_set(l, std::min(mid, r), delta);
            if(r > mid) rc->modify_set(std::max(mid, l), r, delta);
            
            update();
        }
    }

    long long query_sum(int l, int r) {                  //区间查询
        if(l == this->l && r == this->r) return sum;
        else{
            pushDown();
            long long ans = 0;
            if(l < mid) ans += lc->query_sum(l, std::min(mid, r));
            if(r > mid) ans += rc->query_sum(std::max(mid, l), r);
            return ans;
        }
    }

    long long query_max(int l, int r) {                  //区间查询
        if(l == this->l && r == this->r) return maxn;
        else{
            pushDown();
            long long ans = -1;
            if(l < mid) ans = std :: max(lc->query_max(l, std::min(mid, r)),ans) ;
            if(r > mid) ans = std :: max(rc->query_max(std::max(mid, l), r),ans);
            return ans;
        }
    }

    long long query_min(int l, int r) {                  //区间查询
        if(l == this->l && r == this->r) return sum;
        else{
            pushDown();
            long long ans = maxll;
            if(l < mid) ans = std :: min (lc->query_min(l, std::min(mid, r)), ans);
            if(r > mid) ans = std :: min (rc->query_min(std::max(mid, l), r), ans);
            return ans;
        }
    }
};


int main() {
    std :: cin >> n >> m;
    for(int i = 1;i <= n;i ++) 
        std :: cin >> a[i];

    static Node st(1,n + 1);
    st.build();

    while(m --) {
        std :: cin >> type >> l >> r;
        if(judgement == 'd') {
            std :: cin >> w;
            st.modify_add(l,r + 1,w);
        }
        else if(judgement == 'e') {
            std :: cin >> w;
            st.modify_set(l,r + 1,w);
        }
        else if(judgement == 'u') {
            std :: cout << st.query_sum(l,r + 1) << "\n";
        }
        else if(judgement == 'a') {
            std :: cout << st.query_max(l,r + 1) << "\n";
        }
        else if(judgement == 'i') {
            std :: cout << st.query_min(l,r + 1) << "\n";
        }
    }
    return 0;
}
