#include <bits/stdc++.h>
#include <unordered_map>
#define MAX 20001

using namespace std;

vector<pair<string, string>> arr;
vector<string> answer;
int maxNum = 0;
bool Visit[MAX] = { 0, };

void dfs(string From, int depth, vector<string>& T) {
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
            T.push_back(To);
            dfs(To, depth + 1, T);
            T.pop_back();
            Visit[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    string Start = "ICN";

    for (int i = 0; i < tickets.size(); i++) {
        string From = tickets[i][0];
        string To = tickets[i][1];

        arr.push_back({ From,To });
    }

    sort(arr.begin(), arr.end());

    vector<string> T;
    T.push_back(Start);

    dfs(Start, 0, T);

    return answer;
}