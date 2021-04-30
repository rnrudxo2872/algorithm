#include <bits/stdc++.h>
#define MAX 501
#define INF 99999999

using namespace std;

int T,K;
int sum[MAX] = { 0, };
int dp[MAX][MAX] = { 0, };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();

	cin >> T;
	for (int Case = 0; Case < T; Case++) {
		cin >> K;

		for (int i = 1; i <= K; i++) {
			int tmp;
			cin >> tmp;
			sum[i] = sum[i - 1] + tmp;
		}

		for (int i = 1; i < K; i++) {
			for (int Start = 1; Start + i <= K; Start++) {
				int End = Start + i;
				dp[Start][End] = INF;

				for (int mid = Start; mid < End; mid++) {
					dp[Start][End] = dp[Start][End] < dp[Start][mid] + dp[mid + 1][End] + sum[End] - sum[Start - 1] ?
						dp[Start][End] : dp[Start][mid] + dp[mid + 1][End] + sum[End] - sum[Start - 1];
				}
			}
		}
		cout << dp[1][K] << '\n';
	}
}