#include<iostream>
#include<vector>
#include<queue>
#include<functional>

#define INF 9090909
using namespace std;

int N, E;
int start = 1;
int via[2];
bool possible[3];
vector<pair<int, int>> con[8001];
int dis[8001];

void dijkstra() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;

	qu.push({ 0,start });
	dis[start] = 0;
	while (!qu.empty()) {
		int cur_w = qu.top().first;
		int cur_node = qu.top().second;
		qu.pop();

		for (int i = 0; i < con[cur_node].size(); i++) {
			if (dis[con[cur_node][i].second] > cur_w + con[cur_node][i].first) {
				//cout << "���� ��� : " << cur_node << ", ���� ��� ���� : " << con[cur_node][i].first << endl;
				dis[con[cur_node][i].second] = cur_w + con[cur_node][i].first;
				qu.push({ cur_w + con[cur_node][i].first ,con[cur_node][i].second });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		con[a].push_back({ c,b });
		con[b].push_back({ c,a });
	}
	
	cin >> via[0] >> via[1];

	fill(dis, dis + N + 1, INF);
	long long ans[2] = { 0, };
	dijkstra();

	if (dis[via[0]] == INF || dis[via[1]] == INF) { // v1�� v2�� 1������ �� �� ���� ��
		cout << -1;
		return 0;
	}
	
	start = via[1]; // v2�� ���� ��ĥ ��
	ans[1] += dis[via[1]];
	ans[0] += dis[via[0]]; // v1�� ���� ��ĥ ��

	fill(dis, dis + N + 1, INF);
	dijkstra(); // v1�� v2�� ���� �ִ� �Ÿ��� ���� ��(�����)
	
	ans[1] += dis[via[0]];
	ans[0] += dis[via[0]]; // �ΰ��� ��Ʈ�� ���� ���� ���� ��

	start = N; //������ �������� v1�� v2�� �ִ� �Ÿ��� ���Ѵ�.

	fill(dis, dis + N + 1, INF);
	
	dijkstra(); 

	ans[1] += dis[via[0]];
	ans[0] += dis[via[1]];
	
	if (dis[via[0]] == INF || dis[via[1]] == INF)
		cout << -1;
	else
		cout << min(ans[1], ans[0]);
}