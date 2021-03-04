#include<iostream>
#include<vector>

using namespace std;

#define endl "\n";

int map[10][10] = { 0, };
bool square[10][10]; // 3x3 »óÀÚ
bool col_numbering[10][10];
bool row_numbering[10][10];

void find_answer(int cnt) {
	int col = cnt % 9;
	int row = cnt / 9;

	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}

	if (map[row][col] == 0) {
		for (int i = 1; i < 10; i++) {
			if (row_numbering[row][i] == false &&
				col_numbering[col][i] == false &&
				square[(col / 3) + ((row / 3) * 3)][i] == false) {
				row_numbering[row][i] = true;
				col_numbering[col][i] = true;
				square[(col / 3) + ((row / 3) * 3)][i] = true;

				map[row][col] = i;
				find_answer(cnt + 1);
				map[row][col] = 0;

				row_numbering[row][i] = false;
				col_numbering[col][i] = false;
				square[(col / 3) + ((row / 3) * 3)][i] = false;
			}
		}
	}
	else
		find_answer(cnt + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				square[(j / 3) + ((i / 3) * 3)][map[i][j]] = true;
				row_numbering[i][map[i][j]] = true;
				col_numbering[j][map[i][j]] = true;
			}
		}
	}

	find_answer(0);
}