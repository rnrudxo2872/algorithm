#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int parent[100001] = { 0, -1 }; // 루트인 1은 부모가 없으므로 -1로 제외 처리

void bfs() {
	queue<pair<int, int>> qu;
	for (int i = 0; i < v[1].size(); i++) {
		qu.push(make_pair(1, v[1][i])); // 트리 최상위부터
	}

	while (!qu.empty()) {
		pair<int, int> node = qu.front();
		qu.pop();
		
		parent[node.second] = node.first; // 부모 배열[자식값]에 부모값 입력

		for (int i = 0; i < v[node.second].size(); i++) {
			if (parent[v[node.second][i]] != 0)
				continue;
			qu.push(make_pair(node.second, v[node.second][i]));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int N;
	cin >> N;

	int a, b;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a); // 그래프 서로 연결. front 부모, 나머지 자식.
	}

	bfs();

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";
}