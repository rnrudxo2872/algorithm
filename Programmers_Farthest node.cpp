#include <vector>
#include <queue>

using namespace std;

vector<int> v[20001];
int ans_cnt = 0;
bool visit[20001];

void bfs() {
    queue<pair<int, int>> qu;
    qu.push({ 1,0 });
    int max = 0;
    visit[1] = true;

    while (!qu.empty()) {
        int cur_node = qu.front().first;
        int cur_cnt = qu.front().second;
        qu.pop();

        if (cur_cnt == max)
            ans_cnt++;

        for (int i = 0; i < v[cur_node].size(); i++) {
            int next = v[cur_node][i];
            if (!visit[next]) {
                visit[next] = true;
                qu.push({ next, cur_cnt + 1 });
                if (cur_cnt + 1 > max) {
                    max = cur_cnt + 1;
                    ans_cnt = 0;
                }

            }
        }

    }
}

int solution(int n, vector<vector<int>> edge) {

    for (int i = 0; i < edge.size(); i++) {
        int a, b;
        a = edge[i][0];
        b = edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();

    return ans_cnt;
}