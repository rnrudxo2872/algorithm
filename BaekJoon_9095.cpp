#include<iostream>

using namespace std;

int dp[12];

int main() {
	dp[0] = 0;
	dp[1] = 1; // 1
	dp[2] = 2; // 1+1, 2
	dp[3] = 4; // (1+1+1,2+1) 2의 값에서 모두 +1, (1+2) 1값에서 +2,(3) 0의 값에서 +3
	int T;
	scanf_s("%d", &T);
	int last = 3;
	for (int i = 0; i < T; i++) {
		int n;
		scanf_s("%d", &n);
		if (last < n) {
			for (int j = last + 1; j <= n; j++)
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			last = n;
			printf("%d\n", dp[n]);
		}
		else
			printf("%d\n", dp[n]);
	}
}