#include <string>
#include <vector>

using namespace std;

//유효한 글자판단
bool is_Valid(char ch) {

    //알파벳이라면
    if ((97 <= ch && ch <= 122) || (65 <= ch && ch <= 90))
        return true;

    //숫자라면
    else if (48 <= ch && ch <= 57)
        return true;

    //-, _, . 라면
    else if (ch == '-' || ch == '_' || ch == '.')
        return true;

    //외에 다른 문자라면 유효하지 않다.
    return false;
}

string solution(string new_id) {
    string answer = "";

    bool dote = false;
    for (char ch : new_id) {
        if (!is_Valid(ch))
            continue;

        if (ch == '.') {

            //만약 첫글자로 '.'라면
            if (answer.length() == 0 || dote)
                continue;


            dote = true;

        }
        else {
            dote = false;
        }

        //만약 대문자라면 소문자로 치환
        if (65 <= ch && ch <= 90)
            ch += 32;

        answer += ch;
    }

    //16글자 이상 제거
    if (answer.length() >= 16)
        answer = answer.substr(0, 15);

    //마지막 문자가 '.' 이라면
    if (answer[answer.length() - 1] == '.')
        answer.pop_back();

    //빈 문자열이라면 a 추가
    if (answer.length() == 0)
        answer += 'a';

    //문자열 길이가 2이하라면 3이 될 때까지 마지막 문자 추가 
    if (answer.length() <= 2) {
        char last = answer[answer.length() - 1];

        while (answer.length() < 3)
            answer += last;

    }

    return answer;
}