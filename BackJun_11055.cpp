#include <iostream>

using namespace std;

typedef long long ll;

int dp[1001];
int arr[1001];

int main() {
	int N;
	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf_s("%d", &arr[i]);

	dp[arr[1]] = arr[1]; // �ڱ��ڽ��� �ִ�
	ll ans = arr[1];

	for (int i = 2; i <= N; i++) {
		int max = 0;
		for (int j = 1; j < arr[i]; j++) {
			if (max < dp[j])
				max = dp[j];
		}
		max += arr[i]; // arr[i]�� �ִ밪

		dp[arr[i]] = max;
		if (ans < max)
			ans = max;
	}

	printf("%d\n", ans);
}