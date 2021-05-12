#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

struct Point {
	int row;
	int col;
	int dir;
	int cnt;
};

int N;
char Board[51][51];
queue<Point> Q;
int Visit[51][51][4] = { 0, };
int answer = INF;

int del_point[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool is_valid(int row, int col) {
	//cout << "판별 : " <<row << ", " << col << endl;
	if (0 > row || row > N - 1 || 0 > col || col > N - 1)
		return false;
	if (Board[row][col] == '*')
		return false;

	return true;
}

void get_mirror_num() {
	int init_row = Q.front().row;
	int init_col = Q.front().col;

	while (!Q.empty()) {
		int cur_row = Q.front().row;
		int cur_col = Q.front().col;
		int cur_dir = Q.front().dir;
		int cur_cnt = Q.front().cnt;

		Q.pop();

		if (Board[cur_row][cur_col] == '#' && Visit[cur_row][cur_col][cur_dir] != -1) {
			//cout << "들어옴" << endl;
			answer = answer < cur_cnt ? answer : cur_cnt;
			continue;
		}

		int n_row = 0;
		int n_col = 0;
		int revers_dir = (cur_dir + 2) % 4;

		//거울을 설치할 수 있다면,
		if (Board[cur_row][cur_col] == '!' || Board[cur_row][cur_col] == '#') {
			for (int i = 0; i < 4; i++) {
				if (revers_dir == i)
					continue;

				n_row = cur_row + del_point[i][0];
				n_col = cur_col + del_point[i][1];
				int n_cnt = cur_cnt;

				if (!is_valid(n_row, n_col))
					continue;

				if (cur_dir != i)
					n_cnt++;

				if (Visit[n_row][n_col][i] < n_cnt)
					continue;

				Visit[n_row][n_col][i] = n_cnt;
				Q.push({ n_row,n_col,i, n_cnt });
			}
		}
		else {
			n_row = cur_row + del_point[cur_dir][0];
			n_col = cur_col + del_point[cur_dir][1];
			if (!is_valid(n_row, n_col))
				continue;

			if (Visit[n_row][n_col][cur_dir] < cur_cnt)
				continue;

			Visit[n_row][n_col][cur_dir] = cur_cnt;

			Q.push({ n_row, n_col,cur_dir,cur_cnt });
		}
	}
}

int main() {
	init();

	cin >> N;

	int mir_row = 0;
	int mir_col = 0;

	for (int i = 0; i < N; i++) {
		string Line;
		cin >> Line;

		for (int j = 0; j < Line.length(); j++) {
			Board[i][j] = Line[j];

			for (int k = 0; k < 4; k++)
				Visit[i][j][k] = INF;

			if (Line[j] == '#') {
				mir_row = i;
				mir_col = j;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		Visit[mir_row][mir_col][i] = -1;
		Q.push({ mir_row,mir_col,i,0 });
	}

	get_mirror_num();

	cout << answer << endl;
}