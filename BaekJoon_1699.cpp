#include <iostream>

using namespace std;

int dp[100001] = { 0, };

int smaller(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int N;
	scanf_s("%d", &N);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	int ex = 2;
	for (int i = 4; i <= N; i++) {
		if ((ex * ex) == i) {
			ex++;
			dp[i] = 1;
		}
		else {
			dp[i] = i;
			for (int j = ex - 1; j >= 2; j--) {
				dp[i] = smaller(dp[i], dp[i - (j * j)] + 1);
			}
		}
	}

	printf("%d", dp[N]);
}