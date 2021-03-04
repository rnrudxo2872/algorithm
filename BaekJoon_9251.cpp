#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string arr[2];
int dp[1001][1001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();


	string temp;
	for (int i = 0; i < 2; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	for (int i = 1; i <= arr[0].length(); i++) {
		for (int j = 1; j <= arr[1].length(); j++) {
			if (arr[0][i - 1] == arr[1][j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	
	cout << dp[arr[0].length()][arr[1].length()];
}