#include <bits/stdc++.h>

using namespace std;

int N, M, K;
string Word;
vector<vector<char>> Board;
vector<vector<vector<int>>> DP;
int answer = 0;
int delPoint[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool isValid(int row, int col) {
	if (N <= row || row < 0 || M <= col || col < 0)
		return false;
	return true;
}

int dfs(int row, int col, int idx) {
	if (Word.length()-1 <= idx)
		return 1;
	if (DP[row][col][idx] != -1)
		return DP[row][col][idx];
	DP[row][col][idx] = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= K; j++) {
			int nRow = row + (delPoint[i][0] * j);
			int nCol = col + (delPoint[i][1] * j);

			if (!isValid(nRow, nCol))
				break;
			if(Board[nRow][nCol] == Word[idx + 1])
				DP[row][col][idx] += dfs(nRow, nCol, idx + 1);
		}
	}
	return DP[row][col][idx];
}

int main() {
	init();
	cin >> N >> M >> K;

	Board.resize(N,vector<char>(M));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			Board[i][j] = str[j];
		}
	}
	cin >> Word;
	DP.resize(N, vector<vector<int>>(M, vector<int>(Word.length(),-1)));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Word[0] == Board[i][j])
				answer += dfs(i, j, 0);
		}
	}
	cout << answer;
}