#include<iostream>
#include<vector>

using namespace std;

long long per(long long tem) {
	long long pisano = 0, pisano_1 = 0, pisano_2 = 1;
	int i = 0;
	long mod1 = 0, mod2 =0;
	do {
			pisano = pisano_1 + pisano_2;
			pisano_1 = pisano_2%tem;
			pisano_2 = pisano%tem;
			i++;
	} while (pisano_1 != 0 || pisano_2 != 1);

	return i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<long long> ans;

	int P = 0;
	cin >> P;
	int num = 0,tem=0,push=0;

	for (int i = 0; i < P; i++) {
		cin >> num;
		cin >> tem;
		push = per(tem);
		ans.push_back(push);
	}

	for (int i = 0; i < P; i++) {
		cout << i + 1 << " " << ans[i] << "\n";
	}
}