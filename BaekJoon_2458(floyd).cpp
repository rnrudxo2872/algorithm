#include <bits/stdc++.h>
#define INF 9999999

using namespace std;

int N, M;
int dist[502][502] = { 0, };

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) {
					dist[i][j] = 0;
					continue;
				}
				dist[i][j] = dist[i][k] + dist[k][j] < dist[i][j] ?
					dist[i][k] + dist[k][j] : dist[i][j];
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			dist[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		dist[a][b] = 1;
	}

	floyd();

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;

		for (int j = 1; j <= N; j++) {
			if (dist[i][j] != INF || dist[j][i] != INF)
				cnt++;
		}

		if (cnt == N)
			answer++;
	}

	printf("%d", answer);
}