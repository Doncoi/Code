#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int board[5][5];
int movex[5] = {0, -1, 0, 1, 0}, movey[5] = {0, 0, 1, 0, -1};
int Ox1, Oy1, Ox2, Oy2, dep, f;

int avalible(int a, int b, int k) {          //判断是否能走到(a,b)
	if(board[a][b] != k && a >= 1 && a <= 4 && b >= 1 && b <= 4) {  //(a, b)在棋盘内且(a, b)位置为对方棋子或空白
		return 1;
	} else {
		return 0;
	}
}

int jpg() {
	for(int i = 1;i <= 4;i ++) {
		if(board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {           //判断横行
			return 1;
		}
		if(board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {           //判断纵行
			return 1;
		}
	}
	if(board[1][1]==board[2][2]&&board[2][2]==board[3][3]&&board[3][3]==board[4][4]) {             //判断对角线
		return 1;
	}
    if(board[1][4]==board[2][3]&&board[2][3]==board[3][2]&&board[3][2]==board[4][1]) {             //判断对角线
    	return 1;
    }

    return 0;
}

void dfs(int x, int y, int p, int q, int pre, int step) {
	if(jpg()) {
		f = 1;
		return;
	} else if(step > dep) {
		return;
	}

	for(int i = 1;i <= 4;i ++) {
		int nx = x + movex[i];
		int ny = y + movey[i];
		int np = p + movex[i];
		int nq = q + movey[i];

		if(avalible(nx, ny, pre)) {                      //行黑棋
			swap(board[x][y], board[nx][ny]);            //行棋
	
			dfs(nx, ny, p, q, board[x][y], step + 1);    //搜索

			swap(board[x][y], board[nx][ny]);            //回溯
		}

		if(avalible(np, nq, pre)) {                      //行白棋
			swap(board[p][q], board[np][nq]);            //行棋
	
			dfs(x, y, np, nq, board[p][q], step + 1);    //搜索

			swap(board[p][q], board[np][nq]);            //回溯
		}
	}
}	

int main() {
	for(int i = 1;i <= 4;i ++) {
		for(int j = 1;j <= 4;j ++) {
			char ch;
			cin >> ch;
			if(ch == 'B') {
				board[i][j] = 1;
			} else if(ch == 'W') {
				board[i][j] = 2;
			} else {
				board[i][j] = 3;
			}

			if(board[i][j] == 3 && !Ox1) {
				Ox1 = i;    Oy1 = j;                     //记录两个空位，以此为起点开始搜索
			} else if(board[i][j] == 3) {
				Ox2 = i;    Oy2 = j;
			}
		}
	}

	for(dep = 0; ; dep ++) {
		dfs(Ox1, Oy1, Ox2, Oy2, 1, 1);
		dfs(Ox1, Oy1, Ox2, Oy2, 2, 1);
		if(f) {
			printf("%d", dep);
			return 0;
		}
	}

	return 0;
}
