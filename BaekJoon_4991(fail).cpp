#include <bits/stdc++.h>
#define MAX 21
#define INF 9999999

using namespace std;

struct Node {
	int row;
	int col;
	int time;
};

struct Point {
	int row;
	int col;
};

char Board[MAX][MAX];
queue<Node> Q;
vector<Point> dummy;
vector<Point> se;
int ans = INF;
int delPoint[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool Visit[MAX][MAX] = { 0, };
bool dumVisit[11] = { 0, };
int w, h;
int y = 0, x = 0;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

bool isValid(int row, int col) {
	if (Visit[row][col])
		return false;
	if (0 > row || row >= h || 0 > col || col >= w)
		return false;
	if (Board[row][col] == 'x')
		return false;

	return true;
}

int bfs(Point target) {
	while (!Q.empty()) {
		int curRow = Q.front().row;
		int curCol = Q.front().col;
		int curTime = Q.front().time;
		Q.pop();

		//cout << curRow << " : " << curCol << ", time : " << curTime << endl;
		if (target.row == curRow && target.col == curCol) {
			return curTime;
		}

		for (int i = 0; i < 4; i++) {
			int nRow = curRow + delPoint[i][0];
			int nCol = curCol + delPoint[i][1];

			if (!isValid(nRow, nCol))
				continue;

			Visit[nRow][nCol] = true;
			Q.push({ nRow,nCol,curTime + 1 });
		}
	}
	return -1;
}

void Qinit() {
	queue<Node> empty;
	swap(empty, Q);
}

void dfs(int depth) {
	if (ans == -1)
		return;
	if (depth == dummy.size()) {
		int sum = 0;
		Q.push({ y,x,0 });

		for (int i = 0; i < se.size(); i++) {
			int tmpe = bfs(se[i]);

			if (tmpe == -2)
				ans = -1;

			sum += tmpe;
			//cout << "들어간 값 : "<< se[i].row<<","<<se[i].col << ", 구해진 거리 : " << tmpe << endl;
			Qinit();

			Q.push({ se[i].row,se[i].col, 0 });
			memset(Visit, 0, sizeof(Visit));
		}
		Qinit();
		//cout << "구해진 거리 : "<<  sum << endl;
		ans = ans < sum ? ans : sum;
	}

	for (int i = 0; i < dummy.size(); i++) {
		if (dumVisit[i])
			continue;
		dumVisit[i] = true;
		se.push_back(dummy[i]);
		dfs(depth + 1);
		se.pop_back();
		dumVisit[i] = false;
	}
}

int main() {
	init();

	while (1) {

		ans = INF;
		y = 0, x = 0;

		cin >> w >> h;

		if (w == 0 && h == 0)
			return 0;

		memset(dumVisit, 0, sizeof(dumVisit));

		for (int i = 0; i < h; i++) {
			string tmp;
			cin >> tmp;

			for (int j = 0; j < w; j++) {
				Board[i][j] = tmp[j];
				
				if (tmp[j] == 'o') {
					Visit[i][j] = true;
					y = i;
					x = j;
				}
				else if (tmp[j] == '*') {
					dummy.push_back({ i,j });
				}
			}
		}
		
		
		dfs(0);

		memset(Visit, 0, sizeof(Visit));
		
		//# Q 초기화
		Qinit();

		cout << ans << '\n';
	}
}