#include <bits/stdc++.h>

using namespace std;

int R, C;

char board[502][502];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();

	queue<pair<int, int>> sheep;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string tem;
		cin >> tem;
		for (int j = 0; j < C; j++) {
			board[i][j] = tem[j];
			
			if(tem[j] == 'S')
				sheep.push({ i,j });
		}
	}

	while (!sheep.empty()) {
		pair<int, int> Cur = sheep.front();
		sheep.pop();

		for (int i = 0; i < 4; i++) {
			int nRow = Cur.first + dir[i][0];
			int nCol = Cur.second + dir[i][1];

			if (!(-1 < nRow && nRow < R && -1 < nCol && nCol < C))
				continue;

			if (board[nRow][nCol] == 'W') {
				cout << 0;
				exit(0);
			}
			if (board[nRow][nCol] != 'S')
				board[nRow][nCol] = 'D';
		}
	}

	cout << 1 << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}