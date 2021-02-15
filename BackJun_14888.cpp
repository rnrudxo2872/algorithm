#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int number[12] = { 0, };
bool visit[12];
int operate[13] = { 0, };
vector<int> v;
int N;
ll max_num = -1000000000, min_num = 1000000000;

void dfs() {

	if (v.size() == N - 1) {
		int num = number[0];

		for (int i = 1; i < N; i++) {
			/*cout << "cur num : " <<  num << endl;
			cout << "oper : " << v[i - 1] << endl;*/
			if (v[i - 1] == 1) {
				num += number[i];
			}
			else if (v[i - 1] == 2) {
				num -= number[i];
			}
			else if (v[i - 1] == 3) {
				num *= number[i];
			}
			else {
				num /= number[i];
			}
		}

		if (num > max_num)
			max_num = num;
		if (num < min_num)
			min_num = num;

		return;
	}

	for (int i = 0; i < N - 1; i++) {
		if (visit[i])
			continue;

		v.push_back(operate[i]);
		visit[i] = true;
		dfs();
		visit[i] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	int k = 0;
	for (int i = 1; i <= 4; i++) {
		int op;
		cin >> op;
		if (op != 0) {
			for (int j = k; j < op + k; j++) {
				operate[j] = i;
			}
			k += op;
		}
	}

	dfs();

	cout << max_num << "\n" << min_num;
}