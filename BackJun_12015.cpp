#include <iostream>

using namespace std;

typedef long long ll;

ll arr[1000001];

ll lower_bound(ll* arr, ll num, ll end) {
	int start = 0, mid = 0;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] >= num) // 들어온 수가 arr의 중간값보다 작다면, mid가 끝자리가 된다
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int main() {
	ll N, cnt = 0;
	scanf_s("%lld", &N);

	for (ll i = 0; i < N; i++) {
		ll num;
		scanf_s("%lld", &num);

		if (i == 0 || arr[cnt - 1] < num) {
			arr[cnt] = num;
			cnt++;
		}
		else
			arr[lower_bound(arr, num, cnt - 1)] = num;
	}

	printf("%lld", cnt);
}