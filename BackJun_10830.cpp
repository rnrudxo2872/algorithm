#include<iostream>
#include<cstring>

using namespace std;

typedef long long int LL;

LL map[5][5], ans[5][5];

void powf(LL N, LL a[5][5], LL b[5][5]) {
	LL tem[5][5];
	memset(tem, 0, sizeof(tem));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				tem[i][j] += a[i][k] * b[k][j];
			}
			tem[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = tem[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(map, 0, sizeof(map));
	memset(ans, 0, sizeof(ans));


	LL N = 0, B = 0;

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (i == j) {
				ans[i][j] = 1;
			}
		}
	}


	while (B > 0) {
		if (B % 2) {
			powf(N, ans, map);
		}
		powf(N, map, map);
		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}