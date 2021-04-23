#include <bits/stdc++.h>
#define MAX 51

using namespace std;

int N, K;
bool alphaDic[27] = { 0, };
string listStr[MAX];
int MaxNum = 0;
int Visit[MAX] = { 0, };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

void charSetting() {
	int i = 'a' - 'a';
	alphaDic[i] = true;

	i = 'n' - 'a';
	alphaDic[i] = true;

	i = 't' - 'a';
	alphaDic[i] = true;

	i = 'i' - 'a';
	alphaDic[i] = true;

	i = 'c' - 'a';
	alphaDic[i] = true;
}

void dfs(int depth, int CurIdx) {

	//알 수 있는 글자수를 넘어갈 때,
	if (depth + 5 >= K) {
		int temCnt = 0;

		for (int i = 0; i < N; i++) {
			string tem = listStr[i];
			bool possi = true;

			for (int j = 0; j < tem.length(); j++) {
				int Idx = tem[j] - 'a';

				//사전에 없다면
				if (!alphaDic[Idx]) {
					possi = false;
					break;
				}
			}
			if (possi)
				temCnt++;
		}

		MaxNum = MaxNum > temCnt ? MaxNum : temCnt;
		return;
	}

	for (int i = CurIdx; i < 26; i++) {
		if (alphaDic[i])
			continue;
		alphaDic[i] = true;
		dfs(depth + 1, i);
		alphaDic[i] = false;
	}
}

int main() {
	init();

	cin >> N >> K;

	//기본 글자 a, n, t, i, c  - 5개
	charSetting();

	for (int i = 0; i < N; i++) {
		cin >> listStr[i];
	}

	if (K < 5) {
		cout << 0;
		return 0;
	}

	dfs(0, 1);

	cout << MaxNum;
}