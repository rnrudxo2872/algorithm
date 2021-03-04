#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> v[10001];
bool visit[10001] = { 0, };
ll max_num = 0;
int max_node = 0;

void bfs(int N) {
	queue<pair<ll, ll>> qu;
	for (int i = 0; i < v[N].size(); i++) {
		qu.push(v[N][i]);
	}

	visit[N] = true;

	ll temp = 0;
	while (!qu.empty()) {
		int cur_node = qu.front().first;
		int cur_dis = qu.front().second;

		qu.pop();

		if (visit[cur_node])
			continue;


		if (cur_dis > max_num) {
			max_num = cur_dis;
			max_node = cur_node;
		}
		visit[cur_node] = true;

		for (int i = 0; i < v[cur_node].size(); i++) {
			qu.push({ v[cur_node][i].first, v[cur_node][i].second + cur_dis });
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int N;
	cin >> N;

	int a, b, dis;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> dis;

		v[a].push_back(make_pair(b, dis));
		v[b].push_back(make_pair(a, dis));
	}

	bfs(1);

	fill(visit, visit + N + 1, false);

	bfs(max_node);

	cout << max_num;
}