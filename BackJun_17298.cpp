#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int arr[1000000] = { 0, };
int ans[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int N;
	cin >> N;

	memset(ans, -1, sizeof(ans));

	vector<int> index_stack;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		while (!index_stack.empty() && arr[index_stack.back()] < arr[i]) {
			ans[index_stack.back()] = arr[i];
			index_stack.pop_back();
		}
		index_stack.push_back(i);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
}