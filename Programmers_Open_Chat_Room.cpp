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

    //���̵�� �г��� ��
    unordered_map<string, string> Pair;

    //���ڿ� �ڸ���
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

        //���� �����ͺ��� ���̵� ��Ī
        for (int i = idx; i < CurLen; i++) {
            if (log[i] == 32) {
                idx = i + 1;
                break;
            }

            tem += log[i];
        }

        //���̵� ����
        LogArr[ToIdx].id = tem;

        //���� �г��� ����
        LogArr[ToIdx].name = log.substr(idx, CurLen - idx);

        //���� ����� ���̵� �г����� �����Ƿ� ��ŵ
        if (LogArr[ToIdx].Head.compare("Leave") == 0) {
            ToIdx++;
            continue;
        }
        //���������� ���� �г���
        Pair[LogArr[ToIdx].id] = LogArr[ToIdx].name;

        ToIdx++;
    }

    for (int i = 0; i < ToIdx; i++) {
        string tem = "";

        //���Դ�
        if (LogArr[i].Head.compare("Enter") == 0) {
            tem = Pair[LogArr[i].id] + "���� ���Խ��ϴ�.";
            answer.push_back(tem);
        }
        // ������ �α�
        if (LogArr[i].Head.compare("Leave") == 0) {
            tem = Pair[LogArr[i].id] + "���� �������ϴ�.";
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