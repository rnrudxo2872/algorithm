#include <iostream>

using namespace std;

int dp[1001];

int main() {
	int n;
	scanf_s("%d", &n);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 0; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
		dp[i] %= 10007;
	}
	printf("%d", n);
}