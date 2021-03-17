#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> map;
    unordered_map<string, int> copy_map;

    for (int i = 0; i < gems.size(); i++) { // ���� ���
        map[gems[i]] = 1;
    }

    int sizeOfList = map.size();
    int length = gems.size();

    int start = 1, end = gems.size(); // index�� �������� 1�� ���ؾ� ��.
    int fix_start = 1, fix_end = end, temp = 0;

    queue<string> qu;
    for (int i = 0; i < gems.size(); i++) {
        if (i < temp)
            i = temp;

        string Cur = gems[i];
        copy_map[Cur] += 1; //������ ������ ī��Ʈ
        qu.push(Cur);

        if (copy_map.size() == sizeOfList) {
            while (1) {
                if (copy_map[qu.front()] > 1) {
                    copy_map[qu.front()] -= 1;
                    qu.pop();
                    temp++;
                }
                else
                    break;
            }

            start = temp + 1; //���� ���� index�� �ٲ�
            end = i + 1;

        }

        if (length > end - start) {
            length = end - start;
            fix_start = start;
            fix_end = end;
        }
    }
    answer.push_back(fix_start);
    answer.push_back(fix_end);
    return answer;
}