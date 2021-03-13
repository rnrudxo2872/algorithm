#include <queue>
#include <vector>

using namespace std;

vector<int> arr[20001];
bool visit[20001] = { 0, };
int MaxCnt = 0, Ans = 0;

struct CntNode {
    int node;
    int cnt;
};

void bfs(int start) {
    queue<CntNode> qu;
    qu.push({ start, 0 });
    visit[start] = true;

    while (!qu.empty()) {
        int CurNode = qu.front().node;
        int Cnt = qu.front().cnt;
        qu.pop();
        Ans++;

        if (Cnt > MaxCnt) {
            MaxCnt = Cnt;
            Ans = 1;
        }

        for (int i = 0; i < arr[CurNode].size(); i++) {
            int Next = arr[CurNode][i];
            if (!visit[Next]) {
                visit[Next] = true;
                qu.push({ Next, Cnt + 1 });
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); i++) {
        int from = edge[i][0];
        int to = edge[i][1];

        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    bfs(1);

    return Ans;
}