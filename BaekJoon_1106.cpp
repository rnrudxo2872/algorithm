#include <bits/stdc++.h>
#define MAXC 100001

using namespace std;

int C, N;
int arr[21][2];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();

	cin >> C >> N;

	vector<int> dp(MAXC + 1, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < N; i++) {
		for (int j = arr[i][0]; j <= MAXC; j++) {
			dp[j] = dp[j] > dp[j - arr[i][0]] + arr[i][1] ?
				dp[j] : dp[j - arr[i][0]] + arr[i][1];
		}
	}
	for (int i = 0; i <= MAXC; i++) {
		if (dp[i] >= C) {
			cout << i << endl;
			return 0;
		}
	}
}