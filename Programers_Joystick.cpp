#include <string>
#include <vector>
#include <iostream>

using namespace std;
//abcdefghijklmnopqrstuvwxyz

int differ[21]; // 이름의 각 글자마다 알파벳 크기의 차이
bool visit[21]; // 이름을 바꿨는가
int least = 0;
int answer = 0;

int smaller(int a, int b) {
    if (a > b)
        return b;
    else if (a == b)
        return a;
    else
        return a;
}

void search(int size) {
    int index = 0;
    for (int i = 0; i < least; i++) {
        pair<int, int> ans; // cnt와 index
        int cnt = 0;
        bool right = false;
        for (int i = index + 1; i < size; i++) {
            cnt++;
            if (differ[i] != 0 && !visit[i]) {
                ans.first = cnt;
                ans.second = i;
                right = true;
                break;
            }
        }
        //cout << cnt << endl;

        cnt = 0;
        for (int i = index - 1;;) {
            if (i < 0)
                i = size - 1;
            cnt++;
            if (differ[i] != 0 && !visit[i]) {
                if (!right) {
                    ans.first = cnt;
                    ans.second = i;
                    break;
                }
                else {
                    if (ans.first > cnt)
                        ans.second = i;

                    ans.first = smaller(ans.first, cnt);
                    break;
                }

            }
            i--;
        }
        visit[ans.second] = true;
        answer += (ans.first + differ[ans.second]);
        index = ans.second;
    }
}

int solution(string name) {

    string cur_str = "";


    for (int i = 0; i < name.length(); i++)
        cur_str += 'A';

    for (int i = 0; i < name.length(); i++) {
        differ[i] = smaller(name[i] - 'A', 'Z' - name[i] + 1);
        //cout << differ[i] << endl;
        if (name[i] == 'A') {
            visit[i] = true;
            least++;
        }

    }

    answer += differ[0];
    visit[0] = true;
    if (differ[0] != 0)
        least = name.length() - least - 1;
    else
        least = name.length() - least;
    search(name.length());

    return answer;
}

int main() {
    cout << solution("ABABAAAAABA");
}