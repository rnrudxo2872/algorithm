#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[502][2] = { 0, };
vector<int> Taller[502];
vector<int> Shorter[502];
bool Visit[502][502] = { 0, };

void findFamily(int shorter, int taller) {
	for (int i = 0; i < Taller[taller].size(); i++) {
		int superTaller = Taller[taller][i];

		if (!Visit[superTaller][shorter]) {
			Visit[superTaller][shorter] = true;
			Visit[shorter][superTaller] = true;
			findFamily(shorter, superTaller);
			Shorter[superTaller].push_back(shorter);
			Taller[shorter].push_back(superTaller);

		}
	}

	for (int i = 0; i < Shorter[shorter].size(); i++) {
		int superShorter = Shorter[shorter][i];

		if (!Visit[superShorter][taller]) {
			Visit[superShorter][taller] = true;
			Visit[taller][superShorter] = true;
			findFamily(superShorter, taller);
			Taller[superShorter].push_back(taller);
			Shorter[taller].push_back(superShorter);

		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[i][0] = a; //# 키 작은 사람
		arr[i][1] = b; //# 키 큰 사람
	}

	for (int i = 0; i < M; i++) {
		int shorter = arr[i][0];
		int taller = arr[i][1];

		if (!Visit[shorter][taller]) {
			Visit[shorter][taller] = true;
			Visit[taller][shorter] = true;
			findFamily(shorter, taller);
			Taller[shorter].push_back(taller);
			Shorter[taller].push_back(shorter);

		}
	}

	int answer = 0;

	for (int i = 1; i <= N; i++) {
		int listOfSize = Taller[i].size() + Shorter[i].size();

		if (listOfSize + 1 == N) {
			answer++;
		}
	}

	printf("%d", answer);
}