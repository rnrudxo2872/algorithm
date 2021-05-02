#include<bits/stdc++.h>
#define MAX 500001

using namespace std;

struct node {
	int height;
	int idx;
};

int N;
int tower[MAX] = { 0, };

int main() {
	scanf("%d", &N);

	vector<node> stack;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &tower[i]);
	}

	stack.push_back({ tower[1],1 });
	printf("0 ");
	for (int i = 2; i <= N; i++) {
		if (stack.empty()) {
			stack.push_back({ tower[i],i });
			printf("0 ");
			continue;
		}

		bool find = false;
		while (!stack.empty()) {
			if (tower[i] < stack.back().height) {
				printf("%d ", stack.back().idx);
				find = true;
				break;
			}
			stack.pop_back();
		}
		if (!find)
			printf("0 ");
		stack.push_back({ tower[i],i });
	}
}