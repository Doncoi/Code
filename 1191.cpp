#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define mid (this->l + this->r >> 1)

int n,m,l,r;

struct Node {
	int l, r;
	Node *lc, *rc;
	int sum;
	int lazy;
    bool cover;

	Node(int l,int r) {
		this->l = l, this->r = r;
		sum = lazy = 0;
        cover = false;
	}
    
 	void update(){                  
        sum = lc->sum + rc->sum;      
    }
    
    void addTag(){                   
        this->cover = true;
        this->sum = 0;
    }

    void build(){                    
        if(r - l == 1){
            sum = 1;
        } 
        else{
            lc = new Node(l, mid), lc->build();
            rc = new Node(mid, r), rc->build();
            
            update();
        }
    }

	void modify(int l, int r){   
        if(l == this->l && r == this->r) addTag();
        else{
            if(l < mid) lc->modify(l, std::min(mid, r));
            if(r > mid) rc->modify(std::max(mid, l), r);
            
            update();
        }
    }
};

int main() {
	std :: cin >> n >> m;
    Node st(1,n + 1); 
    st.build();

    while(m --) {
    	std :: cin >> l >> r;
    	st.modify(l,r + 1);
    	std :: cout << st.sum << "\n";
    }
}

