#include<iostream>
#include<algorithm>

using namespace std;

#define INF 9999999

typedef long long ll;

ll dist[401][401];
int V, E;
ll mini = INF;

void floyd_warshall() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) {
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
						if (i == j)
							mini = min(mini, dist[i][j]);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	fill(&dist[0][0], &dist[400][401], INF);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c; // 같은 꼴의 쌍의 정보가 주어지지 않기에 조건문 필요 없음.
	}

	floyd_warshall();

	if (mini != INF)
		cout << mini;
	else
		cout << -1;
}