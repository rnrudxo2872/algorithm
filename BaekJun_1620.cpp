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
		#ios::sync_stdio 같은 cin , cout 을 c를 동기화 시키는 코드 사용시, scanf같은 코드를 중복해서
		사용하면 안된다.
*/

int main() {
	scanf("%d %d", &N, &M);

	string temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		map[temp] = i; // id 조회
		idx_str[i] = temp; // 문자열 조회
	}

	for (int i = 0; i < M; i++) {
		char order[21];
		scanf("%s", order);
		if (65 <= order[0] && order[0] <= 90) // 알파벳 대문자
			printf("%d\n", map[order]);
		else {
			int idx = atoi(order);
			cout << idx_str[idx] << endl;
		}
	}
}