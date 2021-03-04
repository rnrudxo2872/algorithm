#include<iostream>
#include<algorithm>

using namespace std;

#define INF 999999
#define endl "\n"
int N, M, K;
pair<int,int> dist[101][101];

void floyd_warshall(int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j || i == k || j == k)
					continue;
				if (dist[i][k].second != INF && dist[k][j].second != INF
					&& dist[i][k].first + dist[k][j].first <= M 
					&& dist[i][k].second + dist[k][j].second < dist[i][j].second)
					dist[i][j] = { dist[i][k].first + dist[k][j].first,
									dist[i][k].second + dist[k][j].second };
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(); cin.tie();

	int T;
	cin >> T;

	for (int x = 0; x < T; x++) {
		cin >> N >> M >> K;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				dist[i][j].first = INF;
				dist[i][j].second = INF;
			}
		}
		for (int i = 1; i <= N; i++) // dist 초기화, 시작 != 도착
			dist[i][i] = { 0,0 };

		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d; //시작,도착,비용,시간
			if (c <= M && dist[u][v].second > d) // 총 비용 보다 많지 않은 경로이며, 짧은 거리
				dist[u][v] = { c,d };
		}

		floyd_warshall(N);

		if (dist[1][N].second != INF && dist[1][N].first != INF)
			cout << dist[1][N].second << endl;
		else
			cout << "Poor KCM" << endl;
	}
	
}