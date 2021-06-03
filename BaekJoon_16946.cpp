#include<bits/stdc++.h>

using namespace std;

struct point {
	int row;
	int col;
};

struct Node {
	char state;
	int idx;
};

int R, C;
vector<vector<Node>> Board;
vector<vector<bool>> Visit;
vector<int> zeroSecSize;

queue<point> Wall;
int delPoint[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int zeroSectionIdx = 0;
int answer[1001][1001] = { 0, };
void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool isDelValid(int row, int col) {
	if (0 > row || row >= R || 0 > col || col >= C)
		return false;
	if (Visit[row][col])
		return false;
	if (Board[row][col].state != '0')
		return false;

	return true;
}

void bfs(int row, int col) {
	queue<point> Q;
	Q.push({ row,col });
	int cnt = 0;

	while (!Q.empty()) {
		int curRow = Q.front().row;
		int curCol = Q.front().col;
		Q.pop();

		cnt++;
		Board[curRow][curCol].idx = zeroSectionIdx;

		for (int i = 0; i < 4; i++) {
			int nRow = curRow + delPoint[i][0];
			int nCol = curCol + delPoint[i][1];

			if (!isDelValid(nRow, nCol))
				continue;

			Visit[nRow][nCol] = true;
			Q.push({ nRow,nCol });
		}
	}
	zeroSecSize.push_back(cnt);
}

int main() {
	init();

	cin >> R >> C;
	Board.resize(R, vector<Node>(C));
	Visit.resize(R, vector<bool>(C));

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < C; j++) {
			Board[i][j].state = str[j];
			if (str[j] == '1')
				Wall.push({ i,j });
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Board[i][j].state == '0' && !Visit[i][j]) {
				Visit[i][j] = true;
				bfs(i, j);
				zeroSectionIdx++;
			}
		}
	}

	
	while (!Wall.empty()) {
		int curRow = Wall.front().row;
		int curCol = Wall.front().col;
		Wall.pop();
		set<int> Search;
		int targetSum = 0;

		for (int i = 0; i < 4; i++) {
			int nRow = curRow + delPoint[i][0];
			int nCol = curCol + delPoint[i][1];

			if (0 > nRow || nRow >= R || 0 > nCol || nCol >= C)
				continue;
			if (Board[nRow][nCol].state != '0')
				continue;

			int sectionIdx = Board[nRow][nCol].idx;
			if (Search.find(sectionIdx) == Search.end()) {
				Search.insert(sectionIdx);
				targetSum += zeroSecSize[sectionIdx];
			}
		}

		answer[curRow][curCol] = (targetSum + 1) % 10;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << answer[i][j];
		}
		cout << '\n';
	}
}