using namespace std;
typedef long long ll;
ll dp[2000] = { 0, };

ll solution(int n) {
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 1234567;
    }

    return dp[n - 1];
}