#include <iostream>

using namespace std;

int up_dp[1001] = { 0, };
int down_dp[1001] = { 0, };
int arr[1001] = { 0, };
int save[1001][2] = { 0, };

int bigger(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N;
	int max = 0; // 적힌 수열 중 가장 큰 수열을 구함.
	scanf("%d", &N);
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}
	for (int i = 0; i < N; i++) {
		int mm = 0, mn = 0;
		for (int j = 1; j < arr[i]; j++)
			mm = bigger(mm, up_dp[j]);

		for (int j = 1; j < arr[N - 1 - i]; j++)
			mn = bigger(mn, down_dp[j]);

		up_dp[arr[i]] = mm + 1;
		save[i][0] = up_dp[arr[i]];
		down_dp[arr[N - 1 - i]] = mn + 1;
		save[N - 1 - i][1] = down_dp[arr[N - 1 - i]];
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = bigger(save[i][0] + save[i][1], ans);

	ans--;
	printf("%d", ans);
}