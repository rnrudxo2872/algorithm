#include <bits/stdc++.h>

using namespace std;

struct Turtle {
	int x;
	int y;
};

int Board[2001][2001] = { 0, };
int N;
int delTurtle[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool isValid(int x, int y) {
	if (0 > x || x > 2000 || 0 > y || y > 2000)
		return false;
	if (Board[y][x] == 0 || Board[y][x] == 2)
		return false;
	return true;
}

void bfs(int x, int y) {
	queue<Turtle> Q;
	Q.push({ x,y });

	while (!Q.empty()) {
		int curX = Q.front().x;
		int curY = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; ++i) {
			int nX = curX + delTurtle[i][0];
			int nY = curY + delTurtle[i][1];

			if (!isValid(nX, nY))
				continue;

			Board[nY][nX] = 2;
			Q.push({ nX,nY });
		}
	}
}

int main() {
	scanf_s("%d", &N);

	for (int i = 0; i < N; ++i) {
		int x1, y1, x2, y2;
		scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);

		x1 = (x1 + 500) * 2; x2 = (x2 + 500) * 2;
		y1 = (y1 + 500) * 2; y2 = (y2 + 500) * 2;

		for (int j = x1; j <= x2; ++j) {
			Board[y1][j] = 1;
			Board[y2][j] = 1;
		}
		for (int j = y1; j <= y2; ++j) {
			Board[j][x1] = 1;
			Board[j][x2] = 1;
		}
	}

	int answer = Board[1000][1000] == 1 ? 0 : 1;

	for (int i = 0; i < 2001; ++i) {
		for (int j = 0; j < 2001; ++j) {
			if (Board[i][j] == 1) {
				answer++;
				Board[i][j] = 2;
				bfs(j, i);
			}
		}
	}
	printf("%d", answer == 0 ? 0 : answer - 1);
}