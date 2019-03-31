#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#define esp  1e-6   
int n, m;  

struct Node {  
    double x,y;  

    Node() {  
        x = y = 0;  
    };

    Node operator - (const Node &a) {  
        Node t; t.x = x - a.x; t.y = y - a.y;  
        return t;   
    }  
} p1, p2, q1, q2; 

struct vector {  
    double x, y;  

    vector() {  
        x = y = 0;  
    };  

    vector operator = (const Node &a) {  
        this->x = a.x; this->y = a.y;  
        return *this;  
    }  

    double operator * (const vector &a) {  
        return x * a.y - y * a.x;  
    }  
};

int main() {  
    printf("INTERSECTING LINES OUTPUT\n");  
    scanf("%d", &n);  

    for (int i = 1; i <= n; ++ i) {  
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &q1.x, &q1.y, &q2.x, &q2.y);  

        vector t,k,l;  
        t = p1 - q1;  k = q2 - q1;  l = p2 - p1;  
        if (fabs(t * k) < esp && fabs(l * k) < esp)  {  
            printf("LINE\n");  
            continue;  
        }  
        t = p2 - p1; k = q2 - q1;  
        if (fabs(t * k) < esp){  
            printf("NONE\n");  
            continue;  
        }  

        double k1, k2, t1;  
        vector a, b, c;  
        a = p2 - q1; b = q2 - q1;  c = p1 - q1;  
        k1 = a * b;   k2 = b * c;  t1 = k1 / (k1 + k2);  
        
        Node ans;  
        ans.x = p2.x + (p1.x - p2.x) * t1;  
        ans.y = p2.y + (p1.y - p2.y) * t1;  
        printf("POINT %0.2lf %0.2lf\n", ans.x, ans.y);  
    } 

    printf("END OF OUTPUT");  
    return 0;
}  
