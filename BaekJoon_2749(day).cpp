#include <bits/stdc++.h>
#define mod 1000000

using namespace std;

typedef long long ll;

int main() {
	ll N;

	scanf("%lld", &N);

	//초기 3개 피보나치
	ll tmp0 = 0, tmp1 = 1, tmp2 = 1;

	//예외 처리
	if (N == 0)
		printf("%lld", tmp0);
	else if (N == 1)
		printf("%lld", tmp1);
	else if (N == 2)
		printf("%lld", tmp2);
	else {
		N %= (mod / 10) * 15;
		for (ll i = 2; i < N; i++) {

			tmp0 = tmp1 + tmp2;
			tmp0 %= mod;

			tmp1 = tmp2;
			tmp1 %= mod;

			tmp2 = tmp0;
			tmp2 %= mod;
		}
		printf("%lld", tmp0);
	}
}