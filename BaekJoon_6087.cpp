#include <bits/stdc++.h>
#define MaxBoard 101

using namespace std;

struct Node {
	int row;
	int col;
	int dir;
	int mir;
};

int R, C;
char Board[MaxBoard][MaxBoard];
queue<Node> Q;
int mirror = 100000;

//상 하 우 좌
int delNode[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int Visit[MaxBoard][MaxBoard] = { 0, };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool isValid(int row, int col) {

	if (R <= row || row < 0 || C <= col || col < 0)
		return false;
	if (Board[row][col] == '*')
		return false;

	return true;
}

void bfs() {

	while (!Q.empty()) {
		int curRow = Q.front().row;
		int curCol = Q.front().col;
		int curDir = Q.front().dir;
		int curMir = Q.front().mir;
		Q.pop();

		//cout << curRow << " : " << curCol << ", 거울 개수 : " << curMir << endl;

		for (int i = 0; i < 4; i++) {
			int nRow = curRow + delNode[i][0];
			int nCol = curCol + delNode[i][1];
			int tmpCnt = curMir;

			if (!isValid(nRow,nCol))
				continue;
			
			if (i != curDir)
				tmpCnt += 1;
			
			if (Board[nRow][nCol] == 'C' && Visit[nRow][nCol] != -5)
				mirror = mirror < tmpCnt ? mirror : tmpCnt;

			if (Visit[nRow][nCol] == -1)
				Visit[nRow][nCol] = tmpCnt;
			else if (Visit[nRow][nCol] < tmpCnt)
				continue;
			else
				Visit[nRow][nCol] = tmpCnt;

			Q.push({ nRow,nCol,i,tmpCnt });
		}
	}
}

int main() {
	init();

	cin >> C >> R;

	memset(Visit, -1,sizeof(Visit));
	// Board 셋팅
	for (int i = 0; i < R; i++) {
		string Line;
		cin >> Line;

		for (int j = 0; j < C; j++) {
			Board[i][j] = Line[j];

			// 방향을 4개 초기 설정
			if (Line[j] == 'C' && Q.size() == 0) {
				Visit[i][j] = -5;

				for (int k = 0; k < 4; k++)
					Q.push({ i,j,k,0 });
			}
		}
	}
	bfs();


	cout << mirror;
}