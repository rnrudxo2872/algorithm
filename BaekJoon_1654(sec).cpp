#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll K, N;
vector<ll> Arr;

ll solve(int cut) {
	int ret = 0;
	for (int i = 0; i < Arr.size(); i++) {
		int tem = Arr[i] / cut;

		ret += tem;
	}

	return ret;
}

ll binarySearch(ll start, ll end) {
	ll mid = 0;
	ll ret = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		ll div = solve(mid);
		if (div < N) {
			end = mid - 1;
		}
		else {
			if (ret < mid)
				ret = mid;
			start = mid + 1;
		}
	}
	return ret;
}

int main() {
	scanf("%lld %lld", &K, &N);
	Arr.resize(K);

	for (int i = 0; i < K; i++)
		scanf("%lld", &Arr[i]);

	sort(Arr.begin(), Arr.end());

	ll start = 1;
	ll end = Arr.back();
	ll ans;

	ans = binarySearch(start, end);

	printf("%lld", ans);
}