#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int M, N;
int basket[1002][1002] = { 0, };
queue<pair<int,pair<int, int>>> qu;

int del_x[4] = { 0,0,1,-1 };
int del_y[4] = { 1,-1,0,0 };
int ans = 0;
int ex = 0;

void bfs() {
	while (!qu.empty()) {
		int y = qu.front().second.first;
		int x = qu.front().second.second;
		int cnt = qu.front().first;
		ans = cnt;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			if (basket[y + del_y[i]][x + del_x[i]] == -1 || basket[y + del_y[i]][x + del_x[i]] == 1)
				continue;
			ex--;
			basket[y + del_y[i]][x + del_x[i]] = 1;
			qu.push({ cnt + 1,{y + del_y[i],x + del_x[i]} });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(); cin.tie();

	cin >> M >> N; //가로 수, 세로 수

	memset(basket, -1, sizeof(basket));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> basket[i][j];
			if (basket[i][j] == 1)
				qu.push({ 0,{i,j} }); // date와 y,x push
			else if (basket[i][j] == 0)
				ex++;
		}
	}

	bfs();

	if (ex != 0)
		cout << -1;
	else
		cout << ans;
}