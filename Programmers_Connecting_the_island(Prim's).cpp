#include <vector>
#include <queue>

using namespace std;

#define Max 101
bool visit[Max] = { 0, };
vector<pair<int, int>> v[Max];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (int i = 0; i < costs.size(); i++) {
        int Cur = costs[i][0];
        int Next = costs[i][1];
        int Cost = costs[i][2];

        v[Cur].push_back({ Next,Cost });
        v[Next].push_back({ Cur,Cost });
    }
    
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < v[0].size(); i++) {
        int Next = v[0][i].first;
        int Cost = v[0][i].second;

        pq.push({ -Cost,Next });//내림차순이기에 - 로 넣어준다.
    }
    visit[0] = true;

    while (!pq.empty()) {
        int Cur = pq.top().second;
        int Dist = -pq.top().first;
        pq.pop();
        
        if (visit[Cur])
            continue;
        visit[Cur] = true;
        answer += Dist;
        for (int i = 0; i < v[Cur].size(); i++) {
            int Next = v[Cur][i].first;
            int Cost = v[Cur][i].second;
            if (visit[Next])
                continue;
            pq.push({ -Cost, Next });
        }
    }

    return answer;
}