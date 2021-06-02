#include<bits/stdc++.h>

using namespace std;

struct point {
	int row;
	int col;
};

int R, C;
vector<vector<char>> Board;
queue<point> Q;

int delPoint[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool isValid(int row, int col, vector<vector<bool>> Visit) {
	if (0 > row || row >= R || 0 > col || col >= C)
		return false;
	if (Visit[row][col])
		return false;
	if (Board[row][col] != '0')
		return false;
	return true;
}

void bfs(point curNode) {
	int cnt = 1;

	vector<vector<bool>> Visit(R,vector<bool>(C));
	queue<point> onePoint;

	onePoint.push({ curNode.row,curNode.col });
	Visit[curNode.row][curNode.col] = true;

	while (!onePoint.empty()) {
		int curRow = onePoint.front().row;
		int curCol = onePoint.front().col;
		onePoint.pop();

		for (int i = 0; i < 4; i++) {
			int nRow = curRow + delPoint[i][0];
			int nCol = curCol + delPoint[i][1];

			if (!isValid(nRow,nCol,Visit))
				continue;

			cnt++;
			Visit[nRow][nCol] = true;
			onePoint.push({ nRow,nCol });
		}
	}
	char Cnt = (cnt % 10) + 48;
	Board[curNode.row][curNode.col] = Cnt;
}

int main() {
	init();

	cin >> R >> C;
	Board.resize(R,vector<char>(C));

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < C; j++) {
			Board[i][j] = str[j];

			if (str[j] == '1')
				Q.push({ i,j });
		}
	}

	while (!Q.empty()) {
		point curPoint = Q.front();
		bfs(curPoint);
		Q.pop();
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << Board[i][j];
		}
		cout << '\n';
	}
}