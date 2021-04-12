#include <string>
#include <vector>

using namespace std;
string answer = "";

void Solve(string str);

bool check(string str) {
    int cnt = 0;
    for (char ch : str) {
        if (ch == '(')
            cnt++;
        else
            cnt--;

        if (cnt < 0)
            return false;
    }
    return true;
}

void DivSolve(string str, string v) {

    //가로 열기
    answer += '(';

    //문자열 앞 뒤 제거
    string temp = str.substr(1, str.length() - 1);
    temp.pop_back();
    //가로 뒤집기
    for (int i = 0; i < temp.length(); i++) {
        char insert;
        if (temp[i] == '(')
            insert = ')';
        else
            insert = '(';

        temp[i] = insert;
    }
    Solve(v);

    answer += ')';
    answer += temp;
}

void Solve(string str) {
    int cnt = 0;
    string temp = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(')
            cnt++;
        else
            cnt--;

        //가로를 추가해 나간다.
        temp += str[i];

        //가로가 균형잡혔을 때,
        if (cnt == 0) {

            // 올바르지 않을 경우,
            if (!check(temp)) {
                DivSolve(temp, str.substr(i + 1, str.length() - (i + 1)));
                return;
            }
            else {
                answer += temp;
                temp = "";
            }
        }

    }
}

string solution(string p) {
    Solve(p);

    return answer;
}