#include<bits/stdc++.h>
#include<unordered_map>

#define MaxSize 100001

using namespace std;

struct Node {
    string Head;
    string id;
    string name;
};

Node LogArr[MaxSize];

vector<string> solution(vector<string> record) {
    vector<string> answer;

    int ToIdx = 0;
    int CntLog = record.size();

    //아이디와 닉네임 페어링
    unordered_map<string, string> Pair;

    //문자열 자르기
    for (string log : record) {
        int CurLen = log.length();
        int idx = 0;
        string tem = "";

        //log head
        for (int i = 0; i < CurLen; i++) {
            if (log[i] == 32) {
                idx = i + 1;
                break;
            }
            tem += log[i];
        }
        LogArr[ToIdx].Head = tem;
        tem = "";

        //다음 포인터부터 아이디 서칭
        for (int i = idx; i < CurLen; i++) {
            if (log[i] == 32) {
                idx = i + 1;
                break;
            }

            tem += log[i];
        }

        //아이디 저장
        LogArr[ToIdx].id = tem;

        //남은 닉네임 저장
        LogArr[ToIdx].name = log.substr(idx, CurLen - idx);

        //떠난 사람은 아이디 닉네임이 없으므로 스킵
        if (LogArr[ToIdx].Head.compare("Leave") == 0) {
            ToIdx++;
            continue;
        }
        //마지막으로 남긴 닉네임
        Pair[LogArr[ToIdx].id] = LogArr[ToIdx].name;

        ToIdx++;
    }

    for (int i = 0; i < ToIdx; i++) {
        string tem = "";

        //들어왔던
        if (LogArr[i].Head.compare("Enter") == 0) {
            tem = Pair[LogArr[i].id] + "님이 들어왔습니다.";
            answer.push_back(tem);
        }
        // 나갔던 로그
        if (LogArr[i].Head.compare("Leave") == 0) {
            tem = Pair[LogArr[i].id] + "님이 나갔습니다.";
            answer.push_back(tem);
        }
    }

    return answer;
}

int main() {
    vector<string> ans = solution({ "Enter uid1234 Muzi" ,  "Leave uid1234" });
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}