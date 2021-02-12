#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int N, M;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			v.push_back(i);
			dfs(depth + 1);
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> N >> M;

	dfs(0);
}