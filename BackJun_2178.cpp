#include<iostream>
#include<queue>

using namespace std;

int map[102][102];
bool visit[102][102];

int x_v[4] = { 1,-1,0,0 };
int y_v[4] = { 0,0,1,-1 };

void bfs(int h, int w) {
	queue<pair<pair<int, int>, int>> qu;

	qu.push({ {1,1},1 }); // Ã³À½ 1,1 ÁÂÇ¥, ÀÌµ¿ È½¼ö

	while (!qu.empty()) {
		int cur_x = qu.front().first.second;
		int cur_y = qu.front().first.first;
		int cur_cnt = qu.front().second;
		qu.pop();

		if (map[cur_y][cur_x] == 0 || visit[cur_y][cur_x] == true)
			continue;

		if (cur_y == h && cur_x == w) {
			cout << cur_cnt;
			return;
		}

		visit[cur_y][cur_x] = true;

		for (int i = 0; i < 4; i++) {
			qu.push({ {cur_y + y_v[i],cur_x + x_v[i]},cur_cnt + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int h, w;
	cin >> h >> w;

	for (int i = 1; i <= h; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= w; j++) {
			map[i][j] = temp[j - 1] - '0';
		}
	}

	bfs(h, w);
}