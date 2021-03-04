
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll k_arr[10001], n_arr[1000001];

ll max_lest(ll *arr, ll lest, ll size) {
	int N = 0;
	for (int i = 0; i < size; i++) {
		N += arr[i] / lest;
		//cout << "¸ò : " << N << "   " << arr[i] << "lest :" << lest << endl << endl;
	}
	return N;
}

ll dive_solve(ll *k_arr, ll n, ll size, ll lest) {
	ll start = 1, end = lest, mid = 0;
	ll ans = 0, tru = 0;
	while (end >= start) {
		mid = (start + end) / 2;
		tru = max_lest(k_arr, mid, size);
		//cout << "tru : " << tru << "mid " << mid << endl;
		//cout << "start : " << start << "end : " << end << endl;
		if (tru > n) {
			start = mid + 1;
			ans = mid;
		}
		else if (tru < n) {
			end = mid - 1;
		}
		else if (tru == n) {
			//cout << "ans : "<<ans << "mid : " << mid << endl;
			if (ans < mid)
			{
				ans = mid;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}


		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k = 0, n = 0;
	cin >> k; cin >> n;

	ll sum = 0;
	for (long i = 0; i < k; i++) {
		cin >> k_arr[i];
		sum += k_arr[i];
	}
	sum /= n;
	//if (k == 1 && n == 1) {
	//	cout << k_arr[0] << "\n";
	//	return 0;
	//}

	//sort(k_arr, k_arr + k);
	cout << dive_solve(k_arr, n, k, sum) << "\n";
}

