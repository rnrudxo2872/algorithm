#include <bits/stdc++.h>
#define MAX 1500

using namespace std;

int R, C;
char Map[MAX][MAX];
bool Visit[MAX][MAX] = { 0, };
bool Find;
queue<pair<int, int>> WQ, WnQ, SQ, SnQ;

int delPoint[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void SwanBfs() {
	while (!Find && !SQ.empty()) {
		int curRow = SQ.front().first;
		int curCol = SQ.front().second;
		SQ.pop();

		for (int k = 0; k < 4; k++) {
			int nRow = curRow + delPoint[k][0];
			int nCol = curCol + delPoint[k][1];

			if (Visit[nRow][nCol])
				continue;
			if (R <= nRow || nRow < 0 || C <= nCol || nCol < 0)
				continue;

			if (Map[nRow][nCol] == 'L') {
				Visit[nRow][nCol] = true;
				Find = true;
				break;
			}
			else if (Map[nRow][nCol] == '.') {
				Visit[nRow][nCol] = true;
				SQ.push({ nRow,nCol });
			}
			else if (Map[nRow][nCol] == 'X') {
				Visit[nRow][nCol] = true;
				SnQ.push({ nRow,nCol });
			}
		}
	}
}

void WaterBfs() {
	while (!WQ.empty()) {
		int curRow = WQ.front().first;
		int curCol = WQ.front().second;
		WQ.pop();

		for (int k = 0; k < 4; k++) {
			int nRow = curRow + delPoint[k][0];
			int nCol = curCol + delPoint[k][1];

			if (R <= nRow || nRow < 0 || C <= nCol || nCol < 0)
				continue;

			if (Map[nRow][nCol] == 'X') {
				Map[nRow][nCol] = '.';
				WnQ.push({ nRow,nCol });
			}
		}
	}
}

void clearQ(queue<pair<int,int>> &temp){
	queue<pair<int, int>> empty;
	swap(temp, empty);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	int ans = 0;

	cin >> R >> C;
	Find = false;

	for (int i = 0; i < R; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			Map[i][j] = temp[j];

			if (Map[i][j] != 'X')
				WQ.push({ i,j });
			if (Map[i][j] == 'L')
				SQ.push({ i,j });
			
		}
	}
	SQ.pop();
	
	Visit[SQ.front().first][SQ.front().second] = true;

	while (!Find) {
		SwanBfs();
		if (!Find) {
			WaterBfs();

			SQ = SnQ;
			WQ = WnQ;

			clearQ(SnQ);
			clearQ(WnQ);

			ans++;
		}
	}
	cout << ans;
}