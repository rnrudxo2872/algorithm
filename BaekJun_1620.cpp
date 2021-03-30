#include <iostream>
#include <unordered_map>
#include <string>
#define endl '\n'
#define Max 100001

using namespace std;

unordered_map<string, int> map;
string idx_str[Max];
int N, M;

/*
		#ios::sync_stdio ���� cin , cout �� c�� ����ȭ ��Ű�� �ڵ� ����, scanf���� �ڵ带 �ߺ��ؼ�
		����ϸ� �ȵȴ�.
*/

int main() {
	scanf("%d %d", &N, &M);

	string temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		map[temp] = i; // id ��ȸ
		idx_str[i] = temp; // ���ڿ� ��ȸ
	}

	for (int i = 0; i < M; i++) {
		char order[21];
		scanf("%s", order);
		if (65 <= order[0] && order[0] <= 90) // ���ĺ� �빮��
			printf("%d\n", map[order]);
		else {
			int idx = atoi(order);
			cout << idx_str[idx] << endl;
		}
	}
}