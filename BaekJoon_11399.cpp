#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Dum_arr;

void merge(vector<int>& v, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (v[i] < v[j]) {
			Dum_arr[k] = v[i];
			i++;
		}
		else {
			Dum_arr[k] = v[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int z = j; z <= end; z++) {
			Dum_arr[k] = v[z];
			k++;
		}
	}
	else {
		for (int z = i; z <= mid; z++) {
			Dum_arr[k] = v[z];
			k++;
		}
	}

	for (int z = start; z <= end; z++)
		v[z] = Dum_arr[z];
}

void merge_sort(vector<int>& v, int start, int end) {
	if (Dum_arr.size() == 0)
		Dum_arr.resize(N);
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(v, start, mid);
		merge_sort(v, mid + 1, end);
		merge(v, start, mid, end);
	}
}

int main() {
	vector <int> arr;
	scanf_s("%d", &N);
	arr.resize(N);
	
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);

	merge_sort(arr,0,arr.size() - 1);

	int sum = 0;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		temp += arr[i];
		sum += temp;
	cout << sum << endl;
	}
}