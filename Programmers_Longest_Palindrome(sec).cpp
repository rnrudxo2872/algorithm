#include <iostream>
#include <string>

using namespace std;

bool possible[2501][2501] = { 0, }; //[]���� []���� �����Ѱ�?

int solution(string s)
{
    int length = s.length();

    for (int i = 0; i < length; i++)
        possible[i][i] = true; // ���̰� 1�� �縰.
    int answer = 1;

    for (int i = 0; i < length - 1; i++) {
        if (s[i] == s[i + 1]) {
            possible[i][i + 1] = true; // ���̰� 2�� �縰.
            answer = 2;
        }
    }


    for (int len = 3; len <= length; len++) {
        for (int i = 0; i <= length - len; i++) {
            int Start = i;
            int End = Start + len - 1;

            if (s[Start] == s[End] && possible[Start + 1][End - 1]) {
                answer = len;
                cout << answer << endl;
                possible[Start][End] = true;
            }
        }
    }

    return answer;
}

int main() { 
    cout << solution("abcdcba");
}