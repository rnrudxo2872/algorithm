#include <bits/stdc++.h>

using namespace std;

struct Node {
	int doing;
	int active;
};

int N, M;
int minCost = 9110000000;
bool Visit[101] = { 0, };
vector<int> activArr;
Node arr[101];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

void dfs(int curCost, int acCost) {
	if (curCost >= M) {

		minCost = minCost < acCost ? minCost : acCost;
		
		//# ¾Ö¸Å
		return;
	}

	for (int i = 0; i < N; i++) {
		if (Visit[i])
			continue;
		Visit[i] = true;
		dfs(curCost + arr[i].doing, acCost + arr[i].active);
		Visit[i] = false;
	}
}

int main() {
	init();
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].doing;
	}

	for (int i = 0; i < N; i++) {
		cin >> arr[i].active;
	}

	dfs(0, 0);

	cout << minCost << '\n';
}