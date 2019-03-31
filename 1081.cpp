#include <iostream>
#include <algorithm>
#define mid (this->l + this->r >> 1)
#define maxn 100005

int n,m;
int a[maxn];
int u,v,w;

struct Node{
    int l, r; // [l, r)
    Node *lc, *rc;                    //两个指向node类型的指针
    int sum;                        
    int lazy;
    
    Node(int l, int r){              
        this->l = l, this->r = r;     //this -> l == node[pre].l
        sum = lazy = 0;
    }
    
    void addTag(int delta){           //延迟标记，不查询不下放
        lazy += delta;                
        sum += delta * (r - l);
    }

    void pushDown(){                  //标记下放
        if(lazy){                     
            lc->addTag(lazy);          
            rc->addTag(lazy);
            
            lazy = 0;
        }
    }

    void update(){                    //由子区间更新
        sum = lc->sum + rc->sum;      
    }
    
    void build(){                     //构造
        if(r - l == 1){
            sum = a[l];
        } 
        else{
            lc = new Node(l, mid), lc->build();
            rc = new Node(mid, r), rc->build();
            
            update();
        }
    }

    void modify(int l, int r, int delta){      //区间修改
        if(l == this->l && r == this->r) addTag(delta);
        else{
            if(l < mid) lc->modify(l, std::min(mid, r), delta);
            if(r > mid) rc->modify(std::max(mid, l), r, delta);
            
            update();
        }
    }

    int query(int index){                      //单点查询
        if(r - l == 1){
            return sum;
        } else{
            pushDown();
            if(index < mid) return lc->query(index);
            else return rc->query(index);
        }
    }
    
};

int main() {
    std :: cin >> n;
    for(int i = 1;i <= n;i ++)
        std :: cin >> a[i];

    Node st(1,n + 1);
    st.build();

    std :: cin >> m;
    while(m--) {
        std :: cin >> u;
        if(u == 1) {
            std :: cin >> u >> v >> w;
            st.modify(u,v + 1,w);
        }
        else {
            std :: cin >> u;
            std :: cout << st.query(u) << "\n";
        }
    }
}

