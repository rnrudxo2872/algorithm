#include <bits/stdc++.h>
#define Max 10001

using namespace std;

typedef long long ll;

//Áö¹æ, ÃÑ ¿¹»ê
ll N, Total;
ll ans;
ll Arr[Max];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

ll Binary_Search(int start, int end) {
	 ll mid = 0;
	 ll Ans = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		ll sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid > Arr[i])
				sum += Arr[i];
			else {
				sum += (mid * (N - i));
				break;
			}
		}
		
		if (sum > Total) {
			end = mid - 1;
		}
		else {
			if (mid > Ans)
				Ans = mid;
			start = mid + 1;
		}
	}
	return Ans;
}

int main() {
	init();

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> Arr[i];
	}
	sort(Arr, Arr + N);
	cin >> Total;

	ll start = 1;
	ll end = Arr[N - 1];
	ll ans = 0;

	// ÃÑ ¿¹»ê
	cout << Binary_Search(start, end) << '\n';

}