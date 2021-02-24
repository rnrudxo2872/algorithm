#include <string>
#include <vector>

using namespace std;

int dp[101][101];
bool visit[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    dp[1][1] = 1;

    for (int i = 0; i < puddles.size(); i++) {
        int y = puddles[i][1];
        int x = puddles[i][0];
        visit[y][x] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visit[i][j] || (i == 1 && j == 1))
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }

    answer = dp[n][m];

    return answer;
}