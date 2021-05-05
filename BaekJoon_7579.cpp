#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[101][2] = { 0, };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();
	int max_active = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i][0];
	for (int i = 0; i < N; i++) {
		cin >> arr[i][1];
		max_active += arr[i][1];
	}

	vector<int> dp(max_active + 1, 0);

	for (int i = 0; i < N; i++) {
		for (int j = max_active; j >= 0; j--) {
			if (j - arr[i][1] < 0)
				break;
			dp[j] = dp[j] > dp[j - arr[i][1]] + arr[i][0] ?
				dp[j] : dp[j - arr[i][1]] + arr[i][0];
		}
	}

	for (int i = 0; i <= max_active; i++) {
		if (dp[i] >= M) {
			printf("%d", i);
			return 0;
		}
	}
}