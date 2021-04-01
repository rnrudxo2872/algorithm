#include <iostream>
#include <queue>
#define Max 27

using namespace std;

struct point {
	int x;
	int y;
};
priority_queue<int> ans;
bool map[Max][Max];
bool visit[Max][Max];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int y, int x) {
	queue<point> qu;
	int house = 1; // 집의 개수
	qu.push({ x,y }); // 첫 시작

	while (!qu.empty()) {
		int Cur_x = qu.front().x;
		int Cur_y = qu.front().y;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int N_x = Cur_x + dx[i];
			int N_y = Cur_y + dy[i];

			if (map[N_y][N_x] && !visit[N_y][N_x]) {
				visit[N_y][N_x] = true;
				house++;
				qu.push({ N_x, N_y });
			}
		}
	}
	ans.push(-house);
}

int main() {
	int N; // 단지 크기와 단지 카운트
	scanf("%d", &N);

	string temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++) { // 가로 세로 같음.
			map[i][j + 1] = temp[j] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j])
				continue;
			if (map[i][j]) {
				visit[i][j] = true;
				bfs(i, j);
			}
		}
	}
	if (ans.size() != 0)
		printf("%d\n", ans.size());
	while (!ans.empty()) {
		printf("%d\n", -ans.top());
		ans.pop();
	}
}