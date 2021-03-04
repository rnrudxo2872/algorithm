#include <iostream>

using namespace std;

int M, N;
int dp[501][501];
int arr[501][501];
int del_x[4] = { 0,0,1,-1 };
int del_y[4] = { 1,-1,0,0 };

int dfs(int x, int y) {
	if (x == N && y == M)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];
	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int dx = del_x[i] + x;
		int dy = del_y[i] + y;
		if (arr[y][x] > arr[dy][dx])
			dp[y][x] += dfs(dx,dy);
	}
	return dp[y][x];
}

int main() {
	scanf_s("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	dp[1][1] = dfs(1, 1);

	printf("%d", dp[1][1]);
}