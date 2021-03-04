#include<vector>
#include<algorithm>

#define Max 101
using namespace std;

vector<pair<int, pair<int, int>>> Cost;
int parent[Max] = { 0, };

int Find_parent(int Node) {
    if (parent[Node] == Node)
        return Node;
    else
        return parent[Node] = Find_parent(parent[Node]);
}

bool Same_parent(int Cur, int Next) {
    int Cur_parent = Find_parent(Cur);
    int Next_parent = Find_parent(Next);

    if (Cur_parent != Next_parent)
        return false;
    else
        return true;
}

void Union(int Cur, int Next) {
    int Cur_parent = Find_parent(Cur);
    int Next_parent = Find_parent(Next);

    parent[Cur_parent] = Next_parent;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < costs.size(); i++) {
        int node = costs[i][0];
        int next = costs[i][1];
        int cost = costs[i][2];

        Cost.push_back({ cost,{ node, next } });
    }

    sort(Cost.begin(), Cost.end());
    for (int i = 0; i < Cost.size(); i++) {
        int CurCost = Cost[i].first;
        int CurNode = Cost[i].second.first;
        int CurNext = Cost[i].second.second;

        if (Same_parent(CurNode, CurNext) == false) {
            Union(CurNode, CurNext);
            answer += CurCost;
        }
    }

    return answer;
}