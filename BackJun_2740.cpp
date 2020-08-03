#include<iostream>
#include<cstring>

using namespace std;

int map1[100][100], map2[100][100], ans[100][100];
int N = 0, M = 0, K = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(map1, 0, sizeof(map1));
	memset(map2, 0, sizeof(map2));
	memset(ans, 0, sizeof(ans));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map1[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++){
		for (int j = 0; j < K; j++) {
			cin >> map2[i][j];
		}
	}	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				ans[i][j] += map1[i][k] * map2[k][j];
			}
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}