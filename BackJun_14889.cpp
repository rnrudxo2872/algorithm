#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int table[21][21] = { 0, };
bool visit[21];
int N;
ll ans = 1000000;

void find(int half, int index) { // 조합으로 구현
	if (half == N / 2) {
		ll start = 0;
		ll link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visit[i] && visit[j]) {
					start += table[i][j] + table[j][i];
				}
				else if(!visit[i] && !visit[j]){
					link += table[i][j] + table[j][i];
				}
			}
		}
		ans = min(ans, abs(start - link));
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visit[i] || index >= i)
				continue;
			visit[i] = true;
			find(half + 1, i);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> table[i][j];
	}

	find(0, -1);

	cout << ans;
}