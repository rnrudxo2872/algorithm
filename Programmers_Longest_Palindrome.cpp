#include <string>

using namespace std;

bool dp[2501][2501] = { 0, }; // []부터 []까지가 palindrome 이다.

int solution(string s)
{
    int answer = 1;
    for (int i = 0; i < s.length(); i++)
        dp[i][i] = true;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            answer = 2;
        }
    }

    for (int Cur = 3; Cur <= s.length(); Cur++) {
        for (int Start = 0; Start <= s.length() - Cur; Start++) {
            int End = Start + Cur - 1;
            if (s[Start] == s[End] && dp[Start + 1][End - 1]) {
                dp[Start][End] = true;
                answer = answer > Cur ? answer : Cur;
            }
        }
    }


    return answer;
}