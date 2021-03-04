#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

typedef long long ll;

void init_node(vector<ll> &arr, vector<ll> &tree, ll node, ll start, ll end) {
	if (start == end) {
		tree[node] = start;
	}
	else {
		ll mid = (start + end) / 2;
		init_node(arr, tree, node * 2, start, mid);
		init_node(arr, tree, node * 2 + 1, mid + 1, end);

		if (arr[tree[node * 2]] >= arr[tree[node * 2 + 1]]) {
			tree[node] = tree[node * 2 + 1];
		}
		else {
			tree[node] = tree[node * 2];
		}
	}
}

ll min_hight(vector<ll>& arr, vector<ll>& tree, ll node, ll start, ll end, ll left, ll right) {
	if (left > end || right < start) {
		return -1;
	}
	else if (left <= start && right >= end) {
		return tree[node];
	}

	ll mid = (start + end) / 2;
	ll min1 = min_hight(arr, tree, node * 2, start, mid, left, right);
	ll min2 = min_hight(arr, tree, node * 2 + 1, mid + 1, end, left, right);

	if (min1 == -1){
		return min2;
	}
	else if (min2 == -1) {
		return min1;
	}
	if (arr[min1] >= arr[min2]) {
		return min2;
	}
	else {
		return min1;
	}
}

ll get_max(vector<ll>& arr, vector<ll>& tree, ll start, ll end) {
	ll arr_size = arr.size();
	ll min = min_hight(arr, tree, 1, 0, arr_size-1, start, end);

	ll ans = arr[min] * (end - start + 1);

	if (min - 1 >= start) {
		ll tem = get_max(arr, tree, start, min - 1);
		if (tem > ans) {
			ans = tem;
		}
	}
	if (min + 1 <= end) {
		ll tem = get_max(arr, tree, min + 1, end);
		if (tem > ans) {
			ans = tem;
		}
	}

	return ans;
}


int main() {
	ll n = 0;
	ll num = 0;
	do {
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<ll> arr;
		for (ll i = 0; i < n; i++) {
			cin >> num;
			arr.push_back(num);
		}
		ll h = (ll)ceil(log2(n));
		ll tree_size = (1 << (h + 1));
		vector<ll> tree(tree_size);
		init_node(arr, tree, 1, 0, n - 1);
		
		cout << get_max(arr, tree, 0, n - 1) << "\n";

	} while (n != 0);
	
	return 0;
}