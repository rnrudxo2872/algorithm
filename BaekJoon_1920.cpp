#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;
vector<int> ans;

bool Binary_search(int find) {
	int left = 0;
	int right = N - 1;
	int mid = 0;
	int ret = N - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (A[mid] == find)
			return true;

		if (A[mid] > find) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return false;
}

int main() {
	scanf_s("%d", &N);
	A.resize(N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}

	// A오름차순
	sort(A.begin(), A.end());

	scanf_s("%d", &M);

	for (int i = 0; i < M; i++) {
		int find;

		scanf_s("%d", &find);

		bool pos = Binary_search(find);
		ans.push_back(pos);
	}

	for (int ret : ans)
		printf("%d\n", ret);
}