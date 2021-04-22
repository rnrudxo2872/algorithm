#include <bits/stdc++.h>
#include <unordered_map>
#define MAX 20001

using namespace std;

vector<pair<string, string>> arr;
vector<string> answer;
int maxNum = 0;
bool Visit[MAX] = { 0, };

bool cmp(pair<string, string>& a, pair<string, string>& b) {
    if (a.first.compare(b.first) == 0) {
        return a.second.compare(b.second) < 0;
    }
    return a.first.compare(b.first) < 0;
}

void dfs(string From, int depth, vector<string>& T) {
    T.push_back(From);
    if (depth > maxNum) {
        answer = T;
        maxNum = depth;
    }

    for (int i = 0; i < arr.size(); i++) {
        string nextFrom = arr[i].first;
        string To = arr[i].second;

        if (Visit[i])
            continue;

        if (From.compare(nextFrom) == 0) {

            Visit[i] = true;

            dfs(To, depth + 1, T);

            Visit[i] = false;
        }
    }
    T.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    string Start = "ICN";

    for (int i = 0; i < tickets.size(); i++) {
        string From = tickets[i][0];
        string To = tickets[i][1];

        arr.push_back({ From,To });
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<string> T;

    dfs(Start, 0, T);

    return answer;
}