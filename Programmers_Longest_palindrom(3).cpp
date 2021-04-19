#include <bits/stdc++.h>
#define Max 2503

using namespace std;

bool dp[Max][Max] = { 0, };

int solution(string s)
{
    if (s.length() == 0)
        return 0;
    int answer = 1;

    //[����][����]�� �縰���
    //1���� �縰����̴�.
    for (int i = 0; i < s.length(); i++)
        dp[i][1] = true;

    //2��¥�� �縰
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            answer = 2;
            dp[i][2] = true;
        }
    }

    //�縰��� ����
    for (int i = 3; i <= s.length(); i++) {

        int Idx = i - 1;
        //�� ���̰� �ִ°�
        for (int j = 0; j < s.length() - Idx; j++) {

            if (s[j] == s[j + Idx] && dp[j + 1][Idx - 1]) {
                answer = i;
                dp[j][i] = true;
            }
        }
    }

    return answer;
}