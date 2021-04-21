#include <bits/stdc++.h>
#define Max 301

using namespace std;

int stair[Max] = { 0, };
int dp[Max] = { 0, };

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &stair[i]);
	}

	dp[0] = stair[0];
	dp[1] = stair[1] + stair[0];
	dp[2] = stair[2] + dp[0] > stair[2] + stair[1] ? stair[2] + dp[0] : stair[2] + stair[1];

	for (int i = 3; i < N; i++) {
		dp[i] = stair[i] + dp[i - 2] > stair[i] + stair[i - 1] + dp[i - 3] ?
			stair[i] + dp[i - 2] : stair[i] + stair[i - 1] + dp[i - 3];
	}

	printf("%d", dp[N - 1]);
}