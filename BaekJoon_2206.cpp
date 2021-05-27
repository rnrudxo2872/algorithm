#include<bits/stdc++.h>

using namespace std;

struct Node {
	int row;
	int col;
	int time;
	bool crash;
};

int Row, Col;
vector<vector<char>> Board;
bool Visit[1001][1001][2] = { 0, };
int delNode[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool isValid(int row, int col, bool crash) {
	if (1 > row || row > Row || 1 > col || col > Col) 
		return false;
	if (Visit[row][col][crash])
		return false;
	if (crash && Board[row][col] == '1')
		return false;
	return true;
}

int bfs() {
	queue<Node> Q;
	Q.push({ 1,1,1,false });
	Visit[1][1][false] = true;

	while (!Q.empty()) {
		int curRow = Q.front().row;
		int curCol = Q.front().col;
		int time = Q.front().time;
		bool curChance = Q.front().crash;

		Q.pop();

		if (curRow == Row && curCol == Col) {
			return time;
		}
		if (Board[curRow][curCol] == '1') {
			curChance = true;
		}

		for (int i = 0; i < 4; i++) {
			int nRow = curRow + delNode[i][0];
			int nCol = curCol + delNode[i][1];
			int tmp_time = time;
			
			if (!isValid(nRow,nCol,curChance))
				continue;
			
			Visit[nRow][nCol][curChance] = true;
			Q.push({ nRow,nCol,tmp_time + 1,curChance });
		}
	}
	return -1;
}

int main() {
	init();

	cin >> Row >> Col;

	Board.resize(Row + 1, vector<char>(Col + 1));

	for (int i = 1; i <= Row; ++i) {

		string str;
		cin >> str;
		for (int j = 0; j < Col; ++j) {
			Board[i][j + 1] = str[j];
		}
	}
	
	int answer = bfs();
	cout << answer;
}