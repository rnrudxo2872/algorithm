#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
ll arr[1000001] = { 0, };
int lower_bound(int a, int size) {
	int start = 0, mid = 0, end = size;
	while (start < end) {
		mid = (start + end) / 2;

		if (arr[mid] >= a)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int main() {
	ll N;
	scanf_s("%lld", &N);

	scanf_s("%lld", &arr[0]);
	ll index = 1;
	
	for (int i = 1; i < N; i++) {
		ll num;
		scanf_s("%lld", &num);

		if (num > arr[index - 1]) {
			arr[index] = num;
			index++;
		}
		else
			arr[lower_bound(num, index - 1)] = num;
	}

	printf("%lld", index);
}