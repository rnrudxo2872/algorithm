#include <bits/stdc++.h>
#define Max 101

using namespace std;

string Str;
string Arr[Max];
bool dp[Max] = { 0, };
int N;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();

	cin >> Str >> N;
	int StrLen = Str.length();

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	//# dp에 해당 문자열이 substr이 됐는지 알려줌.
	// 뒤에서부터 탐색을 하기에 마지막 nullptr역할로 true로 제외시켜준다.
	dp[StrLen] = true;

	for (int i = StrLen - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			int Len = Arr[j].length();
			
			if (Str.find(Arr[j], i) == i && dp[i + Len]) {
				dp[i] = true;
				break;
			}
		}
	}
	cout << dp[0];
}