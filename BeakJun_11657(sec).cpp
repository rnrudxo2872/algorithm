#include <iostream>
#include <vector>
#define INF 999999999

using namespace std;

struct Node {
	int from;
	int to;
	int cost;
};

long long int dist[501] = { 0, };
int N, M;
vector<Node> v;

bool Bellman() {
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].from;
			int to = v[j].to;
			int cost = v[j].cost;

			if (dist[from] == INF)
				continue;
			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int from = v[i].from;
		int to = v[i].to;
		int cost = v[i].cost;

		if (dist[from] == INF)
			continue;
		if (dist[to] > dist[from] + cost)
			return false;
	}
	return true;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++)
		dist[i] = INF;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		v.push_back({ from,to,cost });
	}

	if (!Bellman()) {
		printf("-1");
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == INF) {
			printf("-1\n");
			continue;
		}
		printf("%lld\n", dist[i]);
	}

}