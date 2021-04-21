#include <bits/stdc++.h>
#define sizeOfCard 500001

using namespace std;

int N, M;
int Arr[sizeOfCard];

int upperBound(int find) {
	int start = 0;
	int end = N - 1;
	int mid = 0;
	int ret = N - 1;

	while (start <= end) {
		mid = (start + end) / 2;

		if (Arr[mid] > find) {
			if (mid < ret)
				ret = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return ret;
}

int lowerBound(int find) {
	int start = 0;
	int end = N - 1;
	int mid = 0;
	int ret = N - 1;

	while (start <= end) {
		mid = (start + end) / 2;

		if (Arr[mid] >= find) {
			end = mid - 1;
			if (ret > mid)
				ret = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return ret;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &Arr[i]);

	//오름차순 정렬
	sort(Arr, Arr + N);

	scanf("%d", &M);

	vector<int> ans(M);

	for (int i = 0; i < M; i++) {
		//upper_bound - lower_bound
		int card;
		scanf("%d", &card);

		int uIdx = upperBound(card);
		int lIdx = lowerBound(card);
		if (uIdx == N - 1 && Arr[N - 1] == card) {
			uIdx++;
		}

		ans[i] = uIdx - lIdx;
	}

	for (int item : ans)
		printf("%d ", item);
}