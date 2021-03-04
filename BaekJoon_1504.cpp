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
				//cout << "현재 노드 : " << cur_node << ", 다음 노드 무게 : " << con[cur_node][i].first << endl;
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

	if (dis[via[0]] == INF || dis[via[1]] == INF) { // v1과 v2를 1번에서 갈 수 없을 때
		cout << -1;
		return 0;
	}
	
	start = via[1]; // v2를 먼저 거칠 때
	ans[1] += dis[via[1]];
	ans[0] += dis[via[0]]; // v1를 먼저 거칠 때

	fill(dis, dis + N + 1, INF);
	dijkstra(); // v1과 v2는 서로 최단 거리가 같을 것(양방향)
	
	ans[1] += dis[via[0]];
	ans[0] += dis[via[0]]; // 두가지 루트에 같은 값을 더해 줌

	start = N; //마지막 지점에서 v1과 v2의 최단 거리를 구한다.

	fill(dis, dis + N + 1, INF);
	
	dijkstra(); 

	ans[1] += dis[via[0]];
	ans[0] += dis[via[1]];
	
	if (dis[via[0]] == INF || dis[via[1]] == INF)
		cout << -1;
	else
		cout << min(ans[1], ans[0]);
}