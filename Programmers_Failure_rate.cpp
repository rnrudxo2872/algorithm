#include <bits/stdc++.h>

using namespace std;

struct Node {
    int idx;
    double fail;
};

vector<Node> Fails;

bool cmp(Node& a, Node& b) {
    if (a.fail == b.fail)
        return a.idx < b.idx;
    return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    for (int i = 1; i < N + 1; i++) {
        int Clear = 0;
        int Chall = 0;

        for (int j = 0; j < stages.size(); j++) {
            if (i < stages[j])
                Clear++;

            if (i == stages[j])
                Chall++;
        }
        if (Chall == 0) {
            Fails.push_back({ i,0 });
            continue;
        }

        double Players = Clear + Chall;
        double fail = Chall / Players;

        Fails.push_back({ i,fail });
    }
    sort(Fails.begin(), Fails.end(), cmp);

    for (int i = 0; i < Fails.size(); i++)
        answer.push_back(Fails[i].idx);

    return answer;
}

int main() {
    vector<int> ans = solution(5,{ 2, 1, 2, 6, 2, 4, 3, 3 });
}