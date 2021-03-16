using namespace std;

typedef long long ll;
ll dp[5001] = { 0, };

int solution(int n) {
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = (dp[i - 2] * 3);
        for (int j = 4; j <= i; j += 2)
            dp[i] += dp[i - j] * 2;
        dp[i] %= 1000000007;
    }

    return dp[n];
}