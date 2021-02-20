#include <iostream>
#include <algorithm>

using namespace std;

#define INF 99999999
#define endl "\n"
int N, M;
int dist[101][101];

void floyd_warshall(int n) {
	for (int k = 1; k <= n; k++) { // 중간 지점
		for (int i = 1; i <= n; i++) { // 시작 지점
			for (int j = 1; j <= n; j++) { // 도착 지점
				if (i == j || i == k || j == k)
					continue;
				if (dist[i][k] != INF && dist[k][j] != INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(); cin.tie();

	cin >> N >> M;

	fill(&dist[0][0], &dist[100][101], INF);
	for (int i = 1; i <= N; i++) // 거리 배열 초기화
		dist[i][i] = 0;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(dist[a][b] > c)
			dist[a][b] = c;
	}

	floyd_warshall(N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] != INF)
				cout << dist[i][j] << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
}