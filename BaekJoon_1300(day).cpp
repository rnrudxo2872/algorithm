#include<bits/stdc++.h>

using namespace std;

int N, K;

int binarySearch() {
	int start = 0;
	int end = K;
	int mid = 0;

	while (start < end) {
		mid = (start + end) / 2;
		int cnt = 0;

		for (int i = 1; i <= N; i++) {
			
			// K�� N���� ũ�ٸ� N ī��Ʈ
			cnt += N < mid / i ? N : mid / i;
		}

		if (cnt >= K)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int main() {
	scanf_s("%d %d", &N, &K);

	int ans;
	ans = binarySearch();
	printf("%d", ans);
}