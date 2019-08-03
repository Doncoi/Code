#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAXV 50000
#define MAXE 100000
 
typedef struct{
	int end, weight, next;
}Edge;
Edge edges[MAXE];
 
int n, m;
int enumber, head[MAXV], record[MAXV];
 
int bfs(int s, int flag)
{
	int temp = 0, tempi = s;
	queue<int> q;
	memset(record, -1, sizeof(record));
	record[s] = 0;
	q.push(s);
 
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = head[v]; i != -1; i = edges[i].next){
			int to = edges[i].end;
			if(record[to] == -1){
				record[to] = record[v] + edges[i].weight;
				if(record[to] > temp){
					temp = record[to];
					tempi = to;
				}
				q.push(to);
			}
		}
	}
	return flag ? tempi : temp;
}
 
void addedge(int start, int end, int weight)
{
	edges[enumber].end = end;
	edges[enumber].weight = weight;
	edges[enumber].next = head[start];
	head[start] = enumber++;
}
 
int main()
{
	memset(head, -1, sizeof(head));
 
	int temps, tempe, templ;
	char d;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> temps >> tempe >> templ >> d;
		addedge(temps, tempe, templ);
		addedge(tempe, temps, templ);
	}
 
	int a = bfs(1, 1);
	cout << bfs(a, 0) << endl;
}