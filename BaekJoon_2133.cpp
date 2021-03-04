#include <iostream>

using namespace std;

int dp[31] = { 0, };

int main() {
	int n;
	scanf_s("%d", &n);

	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++) {
		if (i % 2) {
			dp[i] = 0;
			continue;
		}
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j++) {
			dp[i] += dp[i - j] * 2;
		}
	}

	printf("%d", dp[n]);
}