#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N[100001], M[100001];

void search(int* arr, int tem, int start, int end) {

	int mid = (start + end) / 2;

	if (start > end) {
		cout << 0 << "\n";
	}
	else if (arr[mid] > tem) {
		search(arr, tem, start, mid - 1);
	}
	else if (arr[mid] < tem) {
		search(arr, tem, mid + 1, end);
	}
	else {
		cout << 1 << "\n";
		return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int Case = 0, num = 0, mcase = 0;

	cin >> Case;
	for (int i = 0; i < Case; i++) {
		cin >> N[i];
	}
	sort(N, N + Case);

	cin >> mcase;

	for (int i = 0; i < mcase; i++) {
		cin >> M[i];
		search(N, M[i], 0, Case - 1);
	}
}