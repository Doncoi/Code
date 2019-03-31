#include <algorithm>

#define mid (this->l + this->r >> 1)

struct Node{
    int l, r; // [l, r)
    Node *lc, *rc;                    //两个指向node类型的指针
    int sum;                        
    int lazy;
    
    Node(int l, int r){              
        this->l = l, this->r = r;     //this -> l == node[pre].l
        sum = lazy = 0;
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
    
    void modify(int index, int delta){          //单点修改
        if(r - l == 1){
            sum += delta;
        } else{
            if(index < mid) lc->modify(index, delta);
            else rc->modify(index, delta);
            
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
    
    int query(int l, int r){                  //区间查询
        if(l == this->l && r == this->r) return sum;
        else{
            pushDown();
            int ans = 0;
            if(l < mid) ans += lc->query(l, std::min(mid, r));
            if(r > mid) ans += rc->query(std::max(mid, l), r);
            return ans;
        }
    }
};
