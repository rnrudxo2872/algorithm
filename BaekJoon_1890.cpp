#include <iostream>
#define Max 101

using namespace std;

int N;
int map[Max][Max] = { 0, };
long long int dp[Max][Max] = { 0, };

long long int dfs(int y, int x) {
	if (y == N && x == N)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];
	dp[y][x] = 0;

	int right = x + map[y][x];
	int down = y + map[y][x];
	
	if (right <= N)
		dp[y][x] += dfs(y, right);
	if (down <= N)
		dp[y][x] += dfs(down, x);
	return dp[y][x];
}

int main() {
	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}

	printf("%lld", dfs(1,1));
}