#include<iostream>
#include<vector>

using namespace std;

int col[16] = { 0, };
int N, ans;

bool possible(int x) { // 퀸을 놓을 수 있는지 판단하는 function

}

void qeen(int x) {
	if (x == N)
		ans++;
	else {
		for (int i = 1; i <= N; i++) {
			col[x] = i;
			if (possible(i))
				qeen(x + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	cin >> N;

	qeen(0);
}