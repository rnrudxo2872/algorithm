#include <vector>
#include <queue>

#define Max 9999999
using namespace std;

int answer = Max;
int visit[28][28] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; // 좌 우 상 하

void bfs(vector<vector<int>> board) {
    queue<pair<int, pair<int, int>>> qu;
    queue<int> dir; //방향 qu.

    qu.push({ 0,{0,0} }); // cnt, (x,y)
    qu.push({ 0,{0,0} }); // cnt, (x,y)
    dir.push(1); // 0 좌, 1 우, 2 상, 3 하
    dir.push(3);
    visit[0][0] = 1;

    int target = board.size() - 1; // 목표지점 [target][target]
    while (!qu.empty()) {
        int Cnt = qu.front().first;
        int CurX = qu.front().second.first;
        int CurY = qu.front().second.second;
        int Head = dir.front(); // 머리가 0이면 왼쪽, 1이면 오른, 2면 위, 3이면 아래
        qu.pop();
        dir.pop();

        if (CurX == target && CurY == target) {
            answer = answer < Cnt ? answer : Cnt;
            continue; // 최소값 저장 및 계속 진행.
        }
        for (int i = 0; i < 4; i++) {
            int nX = CurX + dx[i];
            int nY = CurY + dy[i];

            if (nX < 0 || nY < 0 || target < nX || target < nY) // 범위 벗어나면,
                continue;
            if (board[nY][nX] || visit[nY][nX] == 1) {
                visit[nY][nX] = 1; // 벽으로 못가게 하고 진행.
                continue;
            }

            int temp = Cnt;
            if (Head == i) // 방향이 같다면,
                temp += 100;
            else // 다르다면,
                temp += 600;

            if (visit[nY][nX] == 0 || visit[nY][nX] >= temp) {
                visit[nY][nX] = temp;
                qu.push({ temp,{nX,nY} });
                dir.push(i); // 방향도 같이 넣어준다.
            }
        }
    }

}

int solution(vector<vector<int>> board) { // 0은 길, 1은 벽.

    bfs(board);

    return answer;
}