#include <iostream>

using namespace std;

struct meeting {
	int start, end;
};

meeting sortMeet[100001];
meeting meetings[100001];

void merge(meeting* data, int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end) {
		if (data[i].end < data[j].end) {
			sortMeet[k] = data[i];
			i++;
		}
		else if (data[i].end == data[j].end && data[i].start < data[j].start) {
			sortMeet[k] = data[i];
			i++;
		}
		else{
			sortMeet[k] = data[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int q = j; q <= end; q++) {
			sortMeet[k] = data[q];
			k++;
		}
	}
	else {
		for (int q = i; q <= mid; q++) {
			sortMeet[k] = data[q];
			k++;
		}
	}

	for (int q = start; q <= end; q++) {
		data[q] = sortMeet[q];
	}
}

void merge_sort(meeting* data, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(data, start, mid);// 좌측 정렬
		merge_sort(data, mid + 1, end);// 우측 정렬
		merge(data, start, mid, end);
	}
}

int main() {
	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &meetings[i].start, &meetings[i].end);
	}

	merge_sort(meetings, 0, N - 1); // 병합정렬
	int fin = 0, cnt = 0;

	for (int i = 0; i < N; i++) {
		if (meetings[i].start >= fin) {
			cnt++;
			fin = meetings[i].end;
		}
	}
	printf("%d", cnt);
}