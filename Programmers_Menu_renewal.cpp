#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> Map[11];
int Len_Max[11] = { 0, };

// Map을 셋팅할 재귀 함수
void Insert_course(string str, int pos, string CurStr) {

    // pointer(pos)가 문자열의 길이를 넘어설 때, 함수 종료
    if (pos >= str.length()) {

        int Len = CurStr.length();
        
        // Map에 카운팅
        Map[Len][CurStr]++;

        // 해당 문자열(course명)이 최대 카운팅보다 많을 때,
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
        
        // 출력시 원소가 오름차순이기 위해 정렬
        sort(str.begin(), str.end());
        Insert_course(str, 0, "");
    }

    for (auto Size : course) {

        int Cur_Max = Len_Max[Size];
        
        // course 카운팅이 2미만이면 제외
        if (Cur_Max < 2)
            continue;

        for (auto item : Map[Size]) {

            string Cur_Str = item.first;
            int Cur_Size = item.second;

            // 해당 길의의 최대 카운트와 매칭이 된다면,
            if (Cur_Size == Cur_Max)
                answer.push_back(Cur_Str);
        }
    }

    // 들어간 메뉴들을 오름차순 정렬
    sort(answer.begin(), answer.end());
    return answer;
}