#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
bool visit[9];

void dfs(int N, int M, int depth) {
	if (M == depth) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (visit[i] != false)
				continue;
			v.push_back(i);
			visit[i] = true;
			dfs(N, M, depth + 1);
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

	dfs(N, M, 0);
}