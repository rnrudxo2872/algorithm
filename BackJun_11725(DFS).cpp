#include<iostream>
#include<vector>

using namespace std;

vector<int> v[100001];
vector<int> cur;
int parent[100001] = { 0, -1 };
bool visit[100001] = { true, true };

void dfs(int depth) {
	if (v[depth].size() == 1) {
		for (int i = cur.size() - 1; i > 0; i--)
			parent[cur[i]] = cur[i - 1];

	}
	else {
		for (int i = 0; i < v[depth].size(); i++) {
			if (visit[v[depth][i]] == true)
				continue;
			cur.push_back(v[depth][i]);
			visit[depth] = true;
			dfs(v[depth][i]);
			visit[depth] = false;
			cur.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a); // 노드들을 서로 연결
	}
	v[1].push_back(0);
	cur.push_back(1);
	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";
}