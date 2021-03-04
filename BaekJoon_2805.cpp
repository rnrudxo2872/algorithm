#include<iostream>

using namespace std;

typedef long long ll;

ll n_arr[1000001], m = 0, n = 0;

ll tree_hight(ll* arr, ll tem, ll size) {
    ll tree_sum = 0;

    for (ll i = 0; i < size; i++) {
        //cout << "sum : " << tree_sum << "tem :" << tem << endl;
        if (arr[i] - tem > 0) {
            tree_sum += arr[i] - tem;
        }
    }

    return tree_sum;
}

ll div_solve(ll* arr, ll max, ll size, ll m) {
    ll start = 0, end = max, mid = 0, ans = 0, tem = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        tem = tree_hight(arr, mid, size);
        //cout << "start : " << start << "end : " << end << "tem : " << tem << "  m :" << m <<endl;

        if (m < tem) {
            ans = mid;
            start = mid + 1;
        }
        else if (m > tem) {
            end = mid - 1;
        }
        else if (m == tem) {
            ans = mid;
            return ans;
        }

    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    ll max = 0;
    for (ll i = 0; i < n; i++) {
        cin >> n_arr[i];
        if (n_arr[i] > max) {
            max = n_arr[i];
        }
    }

    cout << div_solve(n_arr, max, n, m) << "\n";
}