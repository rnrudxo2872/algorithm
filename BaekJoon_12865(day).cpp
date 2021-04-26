#include <bits/stdc++.h>
#define MAX 102
#define MAXMASSIVE 100001

using namespace std;

struct node {
	int W;
	int V;
};

int N, K;
node arr[MAX] = { 0, };
int dp[MAX][MAXMASSIVE] = { 0, };

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N + 1; i++) {
		int W, V;
		scanf("%d %d", &W, &V);

		arr[i].W = W;
		arr[i].V = V;
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j <= K; j++) {
			if (arr[i].W > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] > dp[i - 1][j - arr[i].W] + arr[i].V ?
				dp[i - 1][j] : dp[i - 1][j - arr[i].W] + arr[i].V;
		}
	}

	printf("%d", dp[N][K]);
}