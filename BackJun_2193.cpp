#include <iostream>

using namespace std;
typedef long long ll;

ll dp[91];

int main() {
	int N;
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lld", dp[N]); // long long %lld , long %ld
}