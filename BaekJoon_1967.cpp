#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

vector<pair<int,int>> v[10001];
bool visit[10001] = { 0, };
ll max_num = 0, temp = 0;
int max_node = 0;

void dfs(int start) {
	if (visit[start])
		return;

	if (max_num < temp) {
		max_num = temp;
		max_node = start;
	}
	visit[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		temp += v[start][i].second;
		dfs(v[start][i].first);
		temp -= v[start][i].second;
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

	dfs(1);

	memset(visit, 0, sizeof(visit));

	dfs(max_node);

	cout << max_num;
}