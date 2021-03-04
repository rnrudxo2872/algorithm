#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

ll dp[100001] = { 0, };
ll arr[100001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	ll ans = arr[1];

	dp[1] = arr[1];

	for (int i = 2; i <= N; i++) {
		dp[i] = max(arr[i] + dp[i - 1], arr[i]);
		if (dp[i] > ans)
			ans = dp[i];
	}

	cout << ans;
}