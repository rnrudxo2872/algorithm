#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int N;
string arr[11];
pair<long long, int> Alpha_Cnt[27];
int Size = 0;
pair<long long, int> Dummy[27];

void merge(int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (Alpha_Cnt[i].first < Alpha_Cnt[j].first) {
			Dummy[k] = Alpha_Cnt[j];
			j++;
		}
		else {
			Dummy[k] = Alpha_Cnt[i];
			i++;
		}
		k++;
	}
	if (i > mid) {
		for (int z = j; z <= end; z++) {
			Dummy[k] = Alpha_Cnt[z];
			k++;
		}
	}
	else {
		for (int z = i; z <= mid; z++) {
			Dummy[k] = Alpha_Cnt[z];
			k++;
		}
	}

	for (int z = start; z <= end; z++) {
		Alpha_Cnt[z] = Dummy[z];
	}
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main(){
	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int len = arr[i].length();
		for (int j = 1; j <= len; j++) {
			int idx = arr[i][len - j] - 'A';
			if (Alpha_Cnt[idx].first == 0) // 알파벳 개수를 구한다.
			{
				Size++;
				Alpha_Cnt[idx].second = idx;
			}
			Alpha_Cnt[idx].first += pow(10,j); // 알파 우선권 더함.
		}
	}

	merge_sort(0, 26);
	int Cur_num = 9;
	int idx_num[27] = { 0, };
	
	for (int i = 0; i < Size; i++) {
		idx_num[Alpha_Cnt[i].second] = Cur_num;
		Cur_num--;
	}

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int len = arr[i].length();
		string temp = "";
		
		for (int j = 0; j < len; j++) {
			int idx = arr[i][j] - 'A';
			temp += to_string(idx_num[idx]);
		}
		
		ans += stoi(temp);
	}

	printf("%lld", ans);
}