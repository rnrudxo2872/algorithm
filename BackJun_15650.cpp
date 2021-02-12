#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
bool visit[9];

void dfs(int start, int N, int M, int depth) {
	if (M == depth) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = start; i <= N; i++) {
			if (visit[i] != false)
				continue;
			v.push_back(i);
			visit[i] = true;
			dfs(i, N, M, depth + 1);
			visit[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int N, M;
	cin >> N >> M;

	dfs(1, N, M, 0);
}