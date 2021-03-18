#include <vector>
#include <queue>

#define Max 9999999
using namespace std;

int answer = Max;
int visit[28][28] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; // �� �� �� ��

void bfs(vector<vector<int>> board) {
    queue<pair<int, pair<int, int>>> qu;
    queue<int> dir; //���� qu.

    qu.push({ 0,{0,0} }); // cnt, (x,y)
    qu.push({ 0,{0,0} }); // cnt, (x,y)
    dir.push(1); // 0 ��, 1 ��, 2 ��, 3 ��
    dir.push(3);
    visit[0][0] = 1;

    int target = board.size() - 1; // ��ǥ���� [target][target]
    while (!qu.empty()) {
        int Cnt = qu.front().first;
        int CurX = qu.front().second.first;
        int CurY = qu.front().second.second;
        int Head = dir.front(); // �Ӹ��� 0�̸� ����, 1�̸� ����, 2�� ��, 3�̸� �Ʒ�
        qu.pop();
        dir.pop();

        if (CurX == target && CurY == target) {
            answer = answer < Cnt ? answer : Cnt;
            continue; // �ּҰ� ���� �� ��� ����.
        }
        for (int i = 0; i < 4; i++) {
            int nX = CurX + dx[i];
            int nY = CurY + dy[i];

            if (nX < 0 || nY < 0 || target < nX || target < nY) // ���� �����,
                continue;
            if (board[nY][nX] || visit[nY][nX] == 1) {
                visit[nY][nX] = 1; // ������ ������ �ϰ� ����.
                continue;
            }

            int temp = Cnt;
            if (Head == i) // ������ ���ٸ�,
                temp += 100;
            else // �ٸ��ٸ�,
                temp += 600;

            if (visit[nY][nX] == 0 || visit[nY][nX] >= temp) {
                visit[nY][nX] = temp;
                qu.push({ temp,{nX,nY} });
                dir.push(i); // ���⵵ ���� �־��ش�.
            }
        }
    }

}

int solution(vector<vector<int>> board) { // 0�� ��, 1�� ��.

    bfs(board);

    return answer;
}