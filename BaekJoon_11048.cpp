#include <iostream>

using namespace std;

int map[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int bigger(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N, M;
	scanf_s("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%d", &map[i][j]);
			dp[i][j] = map[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 1 && j == 1)
				continue;
			dp[i][j] = bigger(map[i][j] + dp[i - 1][j - 1], bigger(map[i][j] + dp[i - 1][j], map[i][j] + dp[i][j - 1]));
		}
	}

	printf("%d", dp[N][M]);
}