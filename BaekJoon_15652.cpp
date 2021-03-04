#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int N, M;

void dfs(int start, int depth) {
	if (depth == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = start; i <= N; i++) {
			v.push_back(i);
			dfs(i, depth + 1);
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> N >> M;

	dfs(1, 0);
}