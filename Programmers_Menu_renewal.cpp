#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> Map[11];
int Len_Max[11] = { 0, };

// Map�� ������ ��� �Լ�
void Insert_course(string str, int pos, string CurStr) {

    // pointer(pos)�� ���ڿ��� ���̸� �Ѿ ��, �Լ� ����
    if (pos >= str.length()) {

        int Len = CurStr.length();
        
        // Map�� ī����
        Map[Len][CurStr]++;

        // �ش� ���ڿ�(course��)�� �ִ� ī���ú��� ���� ��,
        if (Map[Len][CurStr] > Len_Max[Len] && CurStr.length() >= 2)
            Len_Max[Len] = Map[Len][CurStr];

        return;
    }

    Insert_course(str, pos + 1, CurStr + str[pos]);
    Insert_course(str, pos + 1, CurStr);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (auto str : orders) {
        
        // ��½� ���Ұ� ���������̱� ���� ����
        sort(str.begin(), str.end());
        Insert_course(str, 0, "");
    }

    for (auto Size : course) {

        int Cur_Max = Len_Max[Size];
        
        // course ī������ 2�̸��̸� ����
        if (Cur_Max < 2)
            continue;

        for (auto item : Map[Size]) {

            string Cur_Str = item.first;
            int Cur_Size = item.second;

            // �ش� ������ �ִ� ī��Ʈ�� ��Ī�� �ȴٸ�,
            if (Cur_Size == Cur_Max)
                answer.push_back(Cur_Str);
        }
    }

    // �� �޴����� �������� ����
    sort(answer.begin(), answer.end());
    return answer;
}