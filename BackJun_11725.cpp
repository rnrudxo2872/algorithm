#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int parent[100001] = { 0, -1 }; // ��Ʈ�� 1�� �θ� �����Ƿ� -1�� ���� ó��

void bfs() {
	queue<pair<int, int>> qu;
	for (int i = 0; i < v[1].size(); i++) {
		qu.push(make_pair(1, v[1][i])); // Ʈ�� �ֻ�������
	}

	while (!qu.empty()) {
		pair<int, int> node = qu.front();
		qu.pop();
		
		parent[node.second] = node.first; // �θ� �迭[�ڽİ�]�� �θ� �Է�

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
		v[b].push_back(a); // �׷��� ���� ����. front �θ�, ������ �ڽ�.
	}

	bfs();

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";
}