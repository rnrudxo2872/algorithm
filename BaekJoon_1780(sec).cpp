#include<iostream>
#include<math.h>

using namespace std;

int N;
int map[2500][2500];
int ans[3];

void div(int xs,int ys, int xe, int ye, int s) {
	int num = map[ys][xs];

	for (int i = ys; i < ye; i++) {
		for (int j = xs; j < xe; j++) {
			if (num != map[i][j]) {
				div(xs, ys, xs + (s / 3), ys + (s / 3), s / 3);
				div(xs + (s / 3), ys, xe - (s / 3), ys + (s / 3), s / 3);
				div(xe - (s / 3), ys, xe, ys + (s / 3), s / 3); // À§ -> ¿Þ, Áß , ¿À

				div(xs, ys + (s / 3), xs + (s / 3), ye - (s / 3), s / 3);
				div(xs + (s / 3), ys + (s / 3), xe - (s / 3), ye - (s / 3), s / 3);
				div(xe - (s / 3), ys + (s / 3), xe, ye - (s / 3), s / 3); // Áß°£ -> ¿Þ, Áß , ¿À

				div(xs, ye - (s / 3), xs + (s / 3), ye, s / 3);
				div(xs + (s / 3), ye - (s / 3), xe - (s / 3), ye, s / 3);
				div(xe - (s / 3), ye - (s / 3), xe, ye, s / 3); // ¾Æ·¡ -> ¿Þ, Áß , ¿À

				return;
			}
		}
	}

	if (num == -1)
		ans[0]++;
	else if (num == 0)
		ans[1]++;
	else
		ans[2]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	div(0, 0, N, N, N);

	for (int i = 0; i < 3; i++)
		cout << ans[i] << "\n";
}