#include<iostream>
#include<vector>

#define INF 99999999
#define endl "\n"

using namespace std;

typedef long long ll;

int N, M;
vector<pair<int, pair<int, int>>> v;
ll dist[501];

void bellman_ford() {
	dist[1] = 0; // 시작 노드 비용.
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].second.first;
			int to = v[j].second.second;
			int cost = v[j].first;

			if (dist[from] == INF)
				continue;
			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int from = v[i].second.first;
		int to = v[i].second.second;
		int cost = v[i].first;

		if (dist[from] == INF)
			continue;
		if (dist[to] > dist[from] + cost) {
			cout << -1;
			exit(0);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back({ c, {a,b} });
	}

	fill(dist, dist + N + 1, INF);

	bellman_ford();

	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF)
			cout << -1 << endl;
		else
			cout << dist[i] << endl;
	}
}