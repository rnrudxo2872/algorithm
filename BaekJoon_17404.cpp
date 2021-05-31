#include<bits/stdc++.h>
#define INF 9999999

using namespace std;

int N;
int answer = INF;
int arr[1001][3] = { 0, };
int dp[1001][3] = { 0, };

int dynamicSol(int idx) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = INF;
	
	//첫집 색 지정
	dp[0][idx] = arr[0][idx];

	//반환 최소값
	int ret = INF;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;

				dp[i][j] = dp[i - 1][k] + arr[i][j] > dp[i][j] ?
					dp[i][j] : dp[i - 1][k] + arr[i][j];
			}
		}
	}

	for (int i = 0; i < 3; i++)
		if (idx != i)
			ret = ret < dp[N - 1][i] ? ret : dp[N - 1][i];

	return ret;
}

int main() {

	scanf_s("%d",&N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		int ret = dynamicSol(i);
		answer = ret < answer ? ret : answer;
	}

	printf("%d\n", answer);
}