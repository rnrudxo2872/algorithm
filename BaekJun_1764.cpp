#include <iostream>
#include <map>
#define endl '\n'

using namespace std;
int N, M;

int main() {
	scanf("%d %d", &N, &M);
	map<string, int> list;
	map<string, int> ans;
	string temp;

	for (int i = 0; i < N; i++) { // �赵 ����
		cin >> temp;
		list[temp] += 1;
	}
	for (int i = 0; i < M; i++) { // ���� ����
		cin >> temp;
		list[temp] += 1;

		if (list[temp] > 1)
			ans[temp] = 1;
	}
	printf("%d\n", ans.size());
	for (auto du : ans)
		cout << du.first << endl;

}