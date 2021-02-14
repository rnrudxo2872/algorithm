#include<iostream>
#include<vector>

using namespace std;

int col[16] = { 0, };
int N, ans;

bool possible(int x) { // 퀸을 놓을 수 있는지 판단하는 function
	for (int i = 1; i < x; i++) {
		if (col[i] == col[x] || abs(x - i) == abs(col[x] - col[i]))
			return false;
	}
	return true;
}

void qeen(int x) {
	if (x == N + 1)
		ans++;
	else {
		for (int i = 1; i <= N; i++) {
			col[x] = i;
			if (possible(x))
				qeen(x + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	cin >> N;

	qeen(1);

	cout << ans;
}