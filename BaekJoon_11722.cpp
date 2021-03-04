#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int N;
	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf_s("%d", &arr[i]);
	int ans = 1;
	dp[arr[N]] = 1; // 처음 arr의 길이. 하나이니까 1이다.
	
	for (int i = N - 1; i >= 1; i--) {
		int length = 0;
		for (int j = arr[i] - 1; j > 0; j--) {
			if (length < dp[j])
				length = dp[j];
		}
		dp[arr[i]] = length + 1;
		if (ans < length + 1)
			ans = length + 1;
	}
	printf("%d", ans);
}