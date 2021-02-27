#include <iostream>

using namespace std;
#define M 10007

int main() {
	int N;
	scanf_s("%d", &N);

	int dp[1001][10] = { 0, };

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k] % M;
				dp[i][j] %= M;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[N][i];
		ans %= M;
	}
	printf("%d", ans);
}