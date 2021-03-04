#include<iostream>
#include<cstring>

#define endl "\n"
using namespace std;

int map[130][130] = { 0, };
int ans[2] = { 0, };

void solve(int xs, int ys, int xe, int ye) {
	int num = map[ys][xs];
	for (int i = ys; i <= ye; i++) {
		for (int j = xs; j <= xe; j++) {
			
			if (num != map[i][j]) {
				solve(xs, ys, (xs+xe) / 2, (ye+ys) / 2);//¿Þ À§
				solve((xe+xs) / 2 + 1, ys, xe, ye / 2);//¿À À§
				solve(xs, (ys+ye )/ 2 + 1, (xs+xe) / 2, ye);//¿Þ ¾Æ·¡
				solve((xs+xe) / 2 + 1, (ye +ys)/ 2 + 1, xe, ye);//¿À ¾Æ·¡
				return;
			}
		}
	}
	ans[num]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	memset(map, -1, sizeof(map));

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	solve(1, 1, N, N);

	cout << ans[0] << endl << ans[1];
}