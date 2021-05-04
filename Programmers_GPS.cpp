#include <bits/stdc++.h>
#define NODE 201
#define INF 9999999

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = 0;
	vector<int> v[NODE];
	for (int i = 0; i < edge_list.size(); i++) {
		int p1 = edge_list[i][0];
		int p2 = edge_list[i][1];

		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}

	//k개의 좌표, k번째를 지정할 후보 지점 개수는 INF로 초기화
	vector<vector<int>> dp(k, vector<int>(n + 1, INF));

	//첫번째 로그를 첫번째 좌표로 지정
	//수정횟수는 0회
	dp[0][gps_log[0]] = 0;

	//2번째 지점부터 지정한다.
	for (int curIdx = 1; curIdx < k; curIdx++) {
		for (int curPoint = 1; curPoint <= n; curPoint++) {
			//이전 가상 지점으로 계산했을 시, 수정횟수가 INF라면
			//연결이 안되어 있다는 것. 스킵
			if (dp[curIdx - 1][curPoint] == INF)
				continue;

			for (int j = 0; j < v[curPoint].size(); j++) {
				int Next = v[curPoint][j];

				int updateCnt = 0;

				if (Next != gps_log[curIdx])
					updateCnt++;

				dp[curIdx][Next] = dp[curIdx][Next] < dp[curIdx - 1][curPoint] + updateCnt ?
					dp[curIdx][Next] : dp[curIdx - 1][curPoint] + updateCnt;
			}
		}
	}
	if (dp[k - 1][gps_log[k - 1]] < INF)
		return dp[k - 1][gps_log[k - 1]];
	return -1;
}