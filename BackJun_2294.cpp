#include <iostream>

using namespace std;

#define MAX 100001
int dp[MAX] = { 0, };
int arr[101] = { 0, };

int smaller(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int n, k;
	scanf_s("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &arr[i]);
	}
	for (int i = 1; i <= k; i++)
		dp[i] = MAX;
	for (int j = 1; j <= n; j++) {
		for (int i = arr[j]; i <= k; i++) {
			dp[i] = smaller(dp[i], dp[i -arr[j]] + 1);
		}
	}
	if (dp[k] == MAX)
		printf("1");
	else
		printf("%d", dp[k]);
}