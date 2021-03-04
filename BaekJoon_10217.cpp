#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>

using namespace std;
#define INF 999999
#define endl "\n"

vector<pair<int, pair<int, int>>> con[101];
int dist[101][10001]; // 항공마다의 비용

void dijkstra(int n, int m) {
	priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qu;
	qu.push({ 0,{ 0,1 } }); // time,cost,node

	while (!qu.empty()) {
		int cur_time = qu.top().first;
		int cur_cost = qu.top().second.first;
		int cur = qu.top().second.second;
		qu.pop();

		if (dist[cur][cur_cost] < cur_time)
			continue;

		for (int i = 0; i < con[cur].size(); i++) {
			int next_time = con[cur][i].first;
			int next_cost = con[cur][i].second.first;
			int next = con[cur][i].second.second;

			if (cur_cost + next_cost > m)
				continue;

			if (dist[next][next_cost + cur_cost] > cur_time + next_time) {
				dist[next][next_cost + cur_cost] = cur_time + next_time;
				qu.push({ cur_time + next_time ,{cur_cost + next_cost, next} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(); cin.tie();

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M, K;
		cin >> N >> M >> K;

		for (int i = 0; i <= N; i++) {
			con[i].clear();
		}
		fill(&dist[0][0], &dist[100][10001], INF); // 항공권 및 dist 초기화
		dist[1][0] = 0;
		for (int i = 0; i < K; i++) {
			int u, v, c, d;//출발,도착,비용,시간
			cin >> u >> v >> c >> d;

			if (c > M)
				continue;
			con[u].push_back({ d,{c,v} });
		}

		dijkstra(N, M);

		int ans = INF;
		for (int k = 1; k <= 10000; k++)
			ans = min(ans, dist[N][k]);

		if (ans != INF)
			cout << ans << endl;
		else
			cout << "Poor KCM" << endl;
	}
}



//1
//6 149 8
//1 2 60 20
//2 3 30 70
//1 3 100 80
//1 3 20 180
//3 4 20 100
//3 5 150 20
//5 6 50 40
//4 6 30 50
//////ans: 240
//////wrong : poor kcm