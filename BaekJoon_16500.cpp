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

	//# dp�� �ش� ���ڿ��� substr�� �ƴ��� �˷���.
	// �ڿ������� Ž���� �ϱ⿡ ������ nullptr���ҷ� true�� ���ܽ����ش�.
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