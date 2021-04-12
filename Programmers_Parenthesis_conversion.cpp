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

    //���� ����
    answer += '(';

    //���ڿ� �� �� ����
    string temp = str.substr(1, str.length() - 1);
    temp.pop_back();
    //���� ������
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

        //���θ� �߰��� ������.
        temp += str[i];

        //���ΰ� ���������� ��,
        if (cnt == 0) {

            // �ùٸ��� ���� ���,
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