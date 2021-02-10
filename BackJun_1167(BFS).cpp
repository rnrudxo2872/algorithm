#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

vector<pair<int, int>> bind[100001];
bool visit[100001];
ll max_num = 0;
int max_node = 0; // 시작했던 곳에서 가장 먼 노드

void bfs(int N) {
	queue<pair<int, int>> qu;
	visit[N] = true;
	for (int i = 0; i < bind[N].size(); i++) {
		qu.push({ bind[N][i].first,bind[N][i].second });
	}

	while (!qu.empty()) {
		int cur_node = qu.front().first;
		int cur_dis = qu.front().second;
		qu.pop();

		if (visit[cur_node])
			continue;
		visit[cur_node] = true;

		if (cur_dis > max_num) {
			max_node = cur_node;
			max_num = cur_dis;
		}
		
		for (int i = 0; i < bind[cur_node].size(); i++) {
			qu.push({ bind[cur_node][i].first, bind[cur_node][i].second + cur_dis }); // 현재 노드와 연결되어 있는
		}																			// 다른 노드들과 그와 떨어진 거리를 합해 큐에 넣는다.
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		while (1) {
			int b;
			cin >> b;
			if (b == -1)
				break;
			int dis;
			cin >> dis;

			bind[a].push_back({ b,dis });
			bind[b].push_back({ a,dis });
		}
	}

	bfs(1);

	fill(visit, visit + N + 1, false);

	bfs(max_node);

	cout << max_num;
}