#include<bits/stdc++.h>

using namespace std;

//금지 리스트 요소의 후보 아이디들
vector<int> Can[10];
int answer = 0;
int Limit;
vector<int> arr;
set<string> Total;
bool Visit[10];

bool isValid(string ban, string user) {
    for (int i = 0; i < ban.length(); i++) {
        if (ban[i] != user[i] && ban[i] != '*')
            return false;
    }
    return true;
}

void dfs(int depth) {
    if (arr.size() == Limit) {
        vector<int> tem = arr;
        sort(tem.begin(), tem.end());
        string tmp = "";
        for (int i = 0; i < tem.size(); i++)
            tmp += to_string(tem[i]);

        Total.insert(tmp);
    }

    for (int i = 0; i < Can[depth].size(); i++) {
        int curStr = Can[depth][i];
        if (Visit[curStr])
            continue;
        Visit[curStr] = true;
        arr.push_back(curStr);
        dfs(depth + 1);
        arr.pop_back();
        Visit[curStr] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {

    for (int i = 0; i < banned_id.size(); i++) {

        int curLen = banned_id[i].length();
        for (int j = 0; j < user_id.size(); j++) {
            int userLen = user_id[j].length();

            if (curLen != userLen)
                continue;
            if (!isValid(banned_id[i], user_id[j]))
                continue;

            Can[i].push_back(j);
        }
    }

    Limit = banned_id.size();
    dfs(0);

    answer = Total.size();
    return answer;
}