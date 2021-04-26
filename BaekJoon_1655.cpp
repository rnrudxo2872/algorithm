#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	priority_queue<int> Head;
	priority_queue<int, vector<int>, greater<int>> Tail;
	
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		int tem;
		scanf_s("%d", &tem);

		if (i == 0) {
			Head.push(tem);
			printf("%d\n", Head.top());
			continue;
		}
		//�켱 ����
		if (Head.size() > Tail.size()) {
			Tail.push(tem);
		}
		else {
			Head.push(tem);
		}

		//���� Head�� Tail���� ũ�ٸ�
		if (Head.top() > Tail.top()) {
			int hTmp = Head.top();
			int tTmp = Tail.top();
			Head.pop();
			Tail.pop();
			
			Head.push(tTmp);
			Tail.push(hTmp);
		}

		printf("%d\n", Head.top());
	}
}