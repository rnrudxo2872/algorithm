#include<iostream>
#include<queue>
#include<vector>

#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	int N, K;
	cin >> N >> K;

	queue<int> qu;
	for (int i = 1; i <= N; i++)
		qu.push(i);

	int cnt = 0;
	vector<int> ans;
	while (!qu.empty()) {
		int front = qu.front();
		qu.pop();
		cnt++;

		if (cnt == K) {
			ans.push_back(front);
			cnt = 0;
		}
		else {
			qu.push(front);
		}
	}

	cout << "<" << ans[0];
	for (int i = 1; i < ans.size(); i++) {
		cout << ", " << ans[i];
	}
	cout << ">";
}