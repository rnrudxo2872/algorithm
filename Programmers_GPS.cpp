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

	//k���� ��ǥ, k��°�� ������ �ĺ� ���� ������ INF�� �ʱ�ȭ
	vector<vector<int>> dp(k, vector<int>(n + 1, INF));

	//ù��° �α׸� ù��° ��ǥ�� ����
	//����Ƚ���� 0ȸ
	dp[0][gps_log[0]] = 0;

	//2��° �������� �����Ѵ�.
	for (int curIdx = 1; curIdx < k; curIdx++) {
		for (int curPoint = 1; curPoint <= n; curPoint++) {
			//���� ���� �������� ������� ��, ����Ƚ���� INF���
			//������ �ȵǾ� �ִٴ� ��. ��ŵ
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