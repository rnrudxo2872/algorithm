#include <iostream>

using namespace std;

int dp[1001][3] = { 0, }; // R,G,B
int map[1001][3] = { 0, };

int main() {
	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}
	dp[0][0] = map[0][0];
	dp[0][1] = map[0][1];
	dp[0][2] = map[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = (dp[i - 1][1] + map[i][0]) < (dp[i - 1][2] + map[i][0]) ? dp[i - 1][1] + map[i][0] : dp[i - 1][2] + map[i][0];
		
		dp[i][1] = (dp[i - 1][0] + map[i][1]) < (dp[i - 1][2] + map[i][1]) ? dp[i - 1][0] + map[i][1] : dp[i - 1][2] + map[i][1];
		
		dp[i][2] = (dp[i - 1][1] + map[i][2]) < (dp[i - 1][0] + map[i][2]) ? dp[i - 1][1] + map[i][2] : dp[i - 1][0] + map[i][2];
	}
	int Min = dp[N - 1][0];
	for (int i = 1; i < 3; i++) {
		Min = Min < dp[N - 1][i] ? Min : dp[N - 1][i];
	}

	printf("%d", Min);
}