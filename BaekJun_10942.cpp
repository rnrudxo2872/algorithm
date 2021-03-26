#include <iostream>
#define Max_Len 2002
#define Max_Ans 1000000

using namespace std;

bool dp[Max_Len][Max_Len];
int Arr[Max_Len];
bool ans[Max_Ans];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &Arr[i]);
		dp[i][i] = true; // 자기자신은 펠린드롭
	}
	for (int i = 1; i < N; i++) { // 2개 짜리
		if (Arr[i] == Arr[i + 1])
			dp[i][i + 1] = true;
	}

	for (int len = 3; len <= N; len++) {
		for (int Start = 1; Start <= N - len + 1; Start++) {
			int End = Start + len - 1;
			if (Arr[Start] == Arr[End] && dp[Start + 1][End - 1])
				dp[Start][End] = true;
		}
	}

	int Quize, a, b;
	scanf("%d", &Quize);

	for (int i = 0; i < Quize; i++) {
		scanf("%d %d", &a, &b);
		ans[i] = dp[a][b];
	}

	for (int i = 0; i < Quize; i++) {
		printf("%d\n", ans[i]);
	}
}