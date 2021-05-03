#include <bits/stdc++.h>
#define MAX 501
#define INF 1999000

using namespace std;

int dp[MAX][MAX] = { 0, };
int sum[MAX] = { 0, };

int main() {
	int T;
	scanf_s("%d", &T);

	for (int i = 0; i < T; i++) {
		int N;
		scanf_s("%d", &N);
		
		for (int j = 1; j <= N; j++) {
			int tmp;
			scanf_s("%d", &tmp);

			sum[j] = sum[j - 1] + tmp;
		}

		for (int add = 1; add < N; add++) {
			
			for (int Start = 1; Start + add <= N; Start++) {

				int End = Start + add;
				dp[Start][End] = INF;

				for (int mid = Start; mid < End; mid++) {
					dp[Start][End] = dp[Start][End] < dp[Start][mid] + dp[mid + 1][End] + sum[End] - sum[Start - 1] ?
						dp[Start][End] : dp[Start][mid] + dp[mid + 1][End] + sum[End] - sum[Start - 1];
				}
			}
		}
		printf("%d\n", dp[1][N]);
	}
}