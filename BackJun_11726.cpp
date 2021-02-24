#include <iostream>

using namespace std;

int dp[1001];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	int N;
	scanf_s("%d", &N);
	for (int i = 4; i <= N; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	printf("%d", dp[N]);
}