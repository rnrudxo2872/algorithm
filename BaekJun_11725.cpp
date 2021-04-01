#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int N;
int visit[100001];

void dfs(int start) {

	for (int i = 0; i < v[start].size(); i++) {
		int Cur = v[start][i];
		if (visit[Cur] != 0)
			continue;
		visit[Cur] = start; // �θ���
		dfs(Cur); // �ڽ��� �θ�� �����ؼ� Ž��;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);

	for (int i = 2; i <= N; i++)
		printf("%d\n", visit[i]);
}