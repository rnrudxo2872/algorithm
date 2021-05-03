#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int N;

int main() {
	vector<int> arr;
	vector<int> ans;
	vector<int> Stack;

	scanf_s("%d", &N);

	arr.resize(N);
	ans.resize(N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	int last_idx = N - 1;
	Stack.push_back(arr[last_idx]);
	ans[last_idx] = -1;

	for (int i = 1; i < N; i++) {
		//���� �ε���
		int curIdx = last_idx - i;
		//���� ����
		int curNum = arr[curIdx];

		//Stack�� ����ִٸ� �ְ� ��������
		if (Stack.empty()) {
			Stack.push_back(curNum);
			continue;
		}

		//���� �� ���� ��(���� ������ ũ�ٸ�,)
		if (Stack.back() > curNum) {
			ans[curIdx] = Stack.back();
			Stack.push_back(curNum);
		}
		else {
			Stack.pop_back();
			
			bool exist = false;

			//��ū���� ã�ƺ���
			while (!Stack.empty()) {
				int curBack = Stack.back();

				if (curBack > curNum) {
					exist = true;
					ans[curIdx] = curBack;
					Stack.push_back(curNum);
					break;
				}
				Stack.pop_back();
			}
			if (!exist) {
				Stack.push_back(curNum);
				ans[curIdx] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d ", ans[i]);
}