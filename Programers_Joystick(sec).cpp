#include <string>
#include <vector>
#include <iostream>

using namespace std;

int smaller(int a, int b) {
    return a > b ? b : a;
}

int solution(string name) {
    int answer = 0;
    int size = name.length();

    string cur_str;
    for (int i = 0; i < size; i++)
        cur_str += 'A';
    
    int index = 0;
    while (cur_str != name) {
        int move = 0;   int point = 0;
        for (int i = 0; i < size; i++) {
            point = move + index;
            bool right = true;
            right = size - 1 < point ? false : true;

            if (right && cur_str[point] != name[point])
                break;

            point = index - move;
            point = 0 > point ? size + index - move : point;

            if (cur_str[point] != name[point])
                break;

            move++;
        }

        answer += smaller(name[point] - 'A', 'Z' - name[point] + 1) + move;
        cur_str[point] = name[point];
        index = point;
    }

    return answer;
}

int main() {
    cout << solution("BBBAAAAAAAAAAB");
}