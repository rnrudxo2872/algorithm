#include <vector>
#define M 1000000007

using namespace std;

int dp[60001] = { 0, };

int solution(int n) {
    int answer = 0;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= M;
    }

    answer = dp[n];

    return answer;
}