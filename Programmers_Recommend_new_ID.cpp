#include <string>
#include <vector>

using namespace std;

//��ȿ�� �����Ǵ�
bool is_Valid(char ch) {

    //���ĺ��̶��
    if ((97 <= ch && ch <= 122) || (65 <= ch && ch <= 90))
        return true;

    //���ڶ��
    else if (48 <= ch && ch <= 57)
        return true;

    //-, _, . ���
    else if (ch == '-' || ch == '_' || ch == '.')
        return true;

    //�ܿ� �ٸ� ���ڶ�� ��ȿ���� �ʴ�.
    return false;
}

string solution(string new_id) {
    string answer = "";

    bool dote = false;
    for (char ch : new_id) {
        if (!is_Valid(ch))
            continue;

        if (ch == '.') {

            //���� ù���ڷ� '.'���
            if (answer.length() == 0 || dote)
                continue;


            dote = true;

        }
        else {
            dote = false;
        }

        //���� �빮�ڶ�� �ҹ��ڷ� ġȯ
        if (65 <= ch && ch <= 90)
            ch += 32;

        answer += ch;
    }

    //16���� �̻� ����
    if (answer.length() >= 16)
        answer = answer.substr(0, 15);

    //������ ���ڰ� '.' �̶��
    if (answer[answer.length() - 1] == '.')
        answer.pop_back();

    //�� ���ڿ��̶�� a �߰�
    if (answer.length() == 0)
        answer += 'a';

    //���ڿ� ���̰� 2���϶�� 3�� �� ������ ������ ���� �߰� 
    if (answer.length() <= 2) {
        char last = answer[answer.length() - 1];

        while (answer.length() < 3)
            answer += last;

    }

    return answer;
}