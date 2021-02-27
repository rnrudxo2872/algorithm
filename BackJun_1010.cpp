#include <iostream>

using namespace std;

int main() {
	int T;
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, M;
		int dp[31][31] = { 0, };
		scanf_s("%d %d", &N, &M);
		for (int i = 1; i <= M; i++){
			dp[1][i] = i;
			dp[i][i] = 1;
		}

		for (int i = 2; i <= N; i++) {
			for (int j = i + 1; j <= M; j++) {
				for (int k = j -1; k >= i - 1; k--) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}

		printf("%d\n", dp[N][M]);
	}
}