#include<bits/stdc++.h>

using namespace std;

struct point {
	int row;
	int col;
};

char board[8][8];
vector<point> block;
bool answer = false;

//À§, À§¿À, ¿À, ¾Æ¿À, ¾Æ·¡, ¾Æ¿Þ, ¿Þ, À§¿Þ
int delPoint[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool isValid(int depth, point curPos) {
	if (7 < curPos.row || curPos.row < 0 || 7 < curPos.col || curPos.col < 0)
		return false;

	for (int i = 0; i < block.size(); i++) {

		if (curPos.row == block[i].row + depth && curPos.col == block[i].col)
			return false;
	}

	return true;
}

void dfs(int depth, point curPos) {
	if (answer)
		return;
	if (depth > 8) {
		answer = true;
		return;
	}
	if (curPos.row == 0 && curPos.col == 7) {
		answer = true;
		return;
	}
	if (!isValid(depth, curPos))
		return;

	dfs(depth + 1, curPos);
	for (int i = 0; i < 8; i++) {
		int nRow = curPos.row + delPoint[i][0];
		int nCol = curPos.col + delPoint[i][1];

		bool flag = true;

		for (int k = 0; k < block.size(); k++) {
			if (nRow == block[k].row + depth && nCol == block[k].col) {
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;

		dfs(depth + 1, { nRow,nCol });
	}
}

int main() {
	init();

	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 8; j++) {
			board[i][j] = str[j];

			if (str[j] == '#')
				block.push_back({ i,j });
		}
	}

	dfs(0, { 7,0 });

	cout << answer;
}