#include<bits/stdc++.h>

using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();
	int N, M;

	//투자 금액, 회사 수
	cin >> N >> M;

	vector<vector<int>> arr(M + 1, vector<int>(N + 1, 0));
	vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
	vector<vector<int>> path(M + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		int money;
		cin >> money;

		// 각 회사마다 money의 투자로 돌려주는 금액
		for (int j = 1; j <= M; j++) {
			cin >> arr[j][money];
		}
	}

	//금액 순차적 검색
	for (int Com = 1; Com <= M; Com++) {
		for (int Money = 1; Money <= N; Money++) {

			for (int dif = 0; dif <= Money; dif++) {
				//이전 회사들의 최대 금액 + 현재 회사에서 
				int Val = dp[Com - 1][Money - dif] + arr[Com][dif];
				if (Val > dp[Com][Money]) {
					dp[Com][Money] = Val;
					path[Com][Money] = dif;
				}
			}
		}
	}

	cout << dp[M][N] << '\n';

	int curMon = N;
	int curCom = M;
	vector<int> ans;
	while (curCom > 0) {
		int Push = path[curCom][curMon];
		ans.push_back(Push);
		curMon -= Push;
		curCom--;
	}

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}