#include <bits/stdc++.h>
#define MAXN 105
#define INF double(INT_MAX)

using namespace std;

struct info{
  int x, y;
};

struct info2{
  double d;
  int u;
};

int i,j,t,k,n,s,A,B,X1,Y1,X2,Y2,X3,Y3,X4,Y4,cnt,uppoint;
int T[MAXN],Pos[MAXN],inheap[MAXN];
double dis[MAXN*4][MAXN*4];
info Point[MAXN*4];
info2 heap[MAXN];
double Mdis,MIN;

template <typename T> void read(T &x) {
 x = 0; char c = getchar();
 for (; !isdigit(c); c = getchar());
 for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
}

double GetDistance(int X1,int Y1,int X2,int Y2) {
  double dis=sqrt(abs(X1-X2)*abs(X1-X2)+abs(Y1-Y2)*abs(Y1-Y2));
  return dis;
}

void GetForthPoint() {
  double D1,D2,D3;
  D1=GetDistance(X1,Y1,X2,Y2); 
  D2=GetDistance(X1,Y1,X3,Y3);
  D3=GetDistance(X2,Y2,X3,Y3);
  if ((D1>D2) && (D1>D3)) { X4=X2-(X3-X1); Y4=Y2-(Y3-Y1); }
  else if ((D2>D1) && (D2>D3)) { X4=X3-(X2-X1); Y4=Y3-(Y2-Y1); }
  else if ((D3>D1) && (D3>D2)) { X4=X3-(X1-X2); Y4=Y3-(Y1-Y2); } 
}

void create_heap(int son) {
   int father=son/2;
   if (father==0) return; 
   if (heap[son].d<heap[father].d) {
     swap(Pos[heap[son].u],Pos[heap[father].u]);
     swap(heap[son],heap[father]);
     create_heap(father);
  }
}

void delete_heap(int father) {
  int son=father*2;
  if (son>cnt) return;
  if ((son+1<=cnt) && (heap[son+1].d<heap[son].d)) son++;
  if (heap[son].d<heap[father].d) {
     swap(Pos[heap[son].u],Pos[heap[father].u]);
     swap(heap[son],heap[father]);
    delete_heap(son);
  }
}

void dijkstra(int k) {
   cnt=0;
   for (i=1;i<=s*4;i++) {
    cnt++; 
   heap[cnt].u=i; heap[cnt].d=dis[k][i]; 
   Pos[i]=i;
   create_heap(cnt);
    inheap[i]=0;
  }
   while (true) {
   if ((heap[1].u>=B*4-3) && (heap[1].u<=B*4)) {
     inheap[heap[1].u]=1;
     Mdis=heap[1].d; uppoint=heap[1].u;
     MIN=min(MIN,heap[1].d);  
       swap(Pos[heap[1].u],Pos[heap[cnt].u]); 
       swap(heap[1],heap[cnt]);
     cnt--;
     delete_heap(1);
   }
   else {
     inheap[heap[1].u]=1;
     Mdis=heap[1].d; uppoint=heap[1].u;
     swap(Pos[heap[1].u],Pos[heap[cnt].u]); 
       swap(heap[1],heap[cnt]); 
     cnt--;
     delete_heap(1);
   }
   if (cnt==0) break;
   for (i=1;i<=s*4;i++) {
     if ((!inheap[i]) && (Mdis+dis[uppoint][i]<heap[Pos[i]].d)) {
       heap[Pos[i]].d=Mdis+dis[uppoint][i]; 
        create_heap(Pos[i]);
     }
   }
  }
}

int main() {
 
  read(n);
  
  for (k=1;k<=n;k++) {
   MIN=INT_MAX;
   read(s); read(t); read(A); read(B);
   for (i=1;i<=s;i++) {
     read(X1); read(Y1); read(X2); read(Y2); 
     read(X3); read(Y3); read(T[i]);
     GetForthPoint();  
     Point[i*4-3].x=X1; Point[i*4-3].y=Y1; 
     Point[i*4-2].x=X2; Point[i*4-2].y=Y2;
     Point[i*4-1].x=X3; Point[i*4-1].y=Y3;
     Point[i*4].x=X4; Point[i*4].y=Y4;
   }
   for (i=1;i<=s*4;i++) {
    for (j=i+1;j<=s*4;j++) {
     if ((i-1)/4==(j-1)/4) dis[i][j]=dis[j][i]=GetDistance(Point[i].x,Point[i].y,Point[j].x,Point[j].y)*T[(i-1)/4+1];
     else dis[i][j]=dis[j][i]=GetDistance(Point[i].x,Point[i].y,Point[j].x,Point[j].y)*t;
    }
   }
   dijkstra(A*4-3); dijkstra(A*4-2); dijkstra(A*4-1); dijkstra(A*4); 
   cout<<fixed<<setprecision(1)<<MIN<<endl;
  }
  
  return 0;
    
}

