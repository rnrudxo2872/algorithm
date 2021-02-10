#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

vector<pair<int, int>> v[100001];
bool visit[100001] = { 0, };
ll max_num = 0, max_node = 1;

void dfs(int start, int tem) {
	if (visit[start] == true)
		return;

	
	if (tem > max_num) {
		max_num = tem;
		max_node = start;
	}

	visit[start] = true;

	for (int i = 0; i < v[start].size(); i++) {
		dfs(v[start][i].first, tem + v[start][i].second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int N;
	cin >> N;
	int a, b, dis;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)
				break;
			cin >> dis;

			v[a].push_back(make_pair(b, dis));
			v[b].push_back(make_pair(a, dis));
		}
	}

	dfs(1, 0);

	fill(visit, visit + N, 0);

	dfs(max_node, 0);

	cout << max_num;
}