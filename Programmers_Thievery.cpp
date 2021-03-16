#include <string>
#include <vector>

using namespace std;

int dp[1000001] = { 0, };

int solution(vector<int> money) {
    int Size = money.size();

    dp[1] = money[0];

    for (int i = 2; i <= Size; i++)
        dp[i] = dp[i - 1] > (dp[i - 2] + money[i - 1]) ? dp[i - 1] : (dp[i - 2] + money[i - 1]);

    long long answer = dp[Size - 1];

    fill(dp, dp + Size, 0);

    dp[2] = money[1];
    for (int i = 3; i <= Size; i++)
        dp[i] = dp[i - 1] > (dp[i - 2] + money[i - 1]) ? dp[i - 1] : (dp[i - 2] + money[i - 1]);

    answer = answer > dp[Size] ? answer : dp[Size];

    return answer;
}