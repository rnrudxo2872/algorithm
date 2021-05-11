#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {

	scanf("%d", &N);
	vector<int> arr(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		scanf("%d",&arr[i]);
	}

	//palindrome
	vector<vector<bool>> palin(N + 1, vector<bool>(N + 1, 0));
	
	//�ڱ��ڽ��� palin
	for (int i = 1; i <= N; i++) {
		palin[i][i] = true;
	}
	
	//2��¥��
	for (int i = 1; i <= N - 1; i++) {
		if (arr[i] == arr[i + 1])
			palin[i][i + 1] = true;
	}

	//��ü ���� Ž��
	for (int Len = 2; Len <= N; ++Len) {
		for (int i = 1; i + Len <= N ; ++i) {
			int Next = i + Len;
			//cout << Next << " " << i << endl;
			if (arr[i] == arr[Next] && palin[i+1][Next-1]) {
				palin[i][Next] = true;
			}
		}
	}

	//����
	scanf("%d",&M);
	for (int i = 0; i < M; i++) {
		int Start, End;
		scanf("%d %d",&Start, &End);
		printf("%d \n", palin[Start][End]);
	}
}