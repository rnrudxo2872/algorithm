#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> arr[101]; // <weight, value>
int dp[101][100001] = { 0, }; // [N][[weight]

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (arr[i].first <= j) // N번째 물건을 넣었을 때 j 무게 때 만들 수 있는 최고 가치 갱신
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
			else // N번째 물건을 못 넣을 때 j 무게 만들 수 있는 최고 가치( = 그 전 물건 넣었을 때 최고가치)
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}