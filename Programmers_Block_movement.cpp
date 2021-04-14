#include <string>
#include <vector>
#include <queue>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

struct Point {
    int row, col;
    int dir, time;
};

struct PPair {
    Point one;
    Point two;
};

int answer = 0;
int N;
vector<vector<int>> Board;
queue<PPair> Q;
bool visit[101][101][4] = { 0, };

//상하좌우
int DELPos[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

//회전축 방향에 따른 회전 좌표의 이동
//역, 정
int DELRot[2][4][2] = { {{1,-1}, {-1,-1}, {-1,1}, {1,1},},
                        {{1,1}, {1,-1}, {-1,-1}, {-1,1}} };

//회전할 때, 모서리 좌표
int RotCon[2][4][2] = { {{-1,-1}, {-1,1}, {1,1}, {1,-1}},
                        {{-1,1}, {1,1}, {1,-1}, {-1,-1}} };

bool isValid(Point Some[2]) {

    for (int i = 0; i < 2; i++) {
        int row = Some[i].row, col = Some[i].col;
        int dir = Some[i].dir, time = Some[i].time;

        //Board의 범위를 넘어선다면,
        if (N - 1 < row || row < 0 || N - 1 < col || col < 0)
            return false;

        //방문한 곳이라면,
        if (visit[row][col][dir])
            return false;

        //벽 이라면,
        if (Board[row][col])
            return false;
    }

    return true;
}

bool rotate(Point Some[2], int Cdir, int fix) {
    int row[2] = { Some[0].row, Some[1].row };
    int col[2] = { Some[0].col, Some[1].col };
    int dir[2] = { Some[0].dir, Some[1].dir };
    int time = Some[0].time;
    int A = fix, B = (fix + 1) % 2;

    Point Next[2];


    //Cdir이 0이면 역, 1이면 정방향
    //회전축 포인트
    Next[0] = { row[A],col[A],(dir[A] + (Cdir ? 1 : 3)) % 4,time + 1 };

    //회전하는 포인트
    Next[1] = { row[B] + DELRot[Cdir][dir[A]][0],col[B] + DELRot[Cdir][dir[A]][1],
                (dir[B] + (Cdir ? 1 : 3)) % 4,time + 1 };

    //회전한 좌표가 유효하지 않다면,
    if (!isValid(Next))
        return false;

    //회전을 할 수 없다면,
    if (Board[row[A] + RotCon[Cdir][dir[A]][0]][col[A] + RotCon[Cdir][dir[A]][1]])
        return false;

    for (int i = 0; i < 2; i++) {
        if (Next[i].col == N - 1 && Next[i].row == N - 1) {
            answer = Next[i].time;
            return true;
        }

        visit[Next[i].row][Next[i].col][Next[i].dir] = true;
    }

    Q.push({ Next[0],Next[1] });
    return false;
}

void MoveRobo() {

    Q.push({ {0,0,RIGHT,0},{0,1,LEFT,0} });
    visit[0][0][RIGHT] = true;
    visit[0][1][LEFT] = true;

    while (!Q.empty()) {
        Point Cur[2] = { Q.front().one, Q.front().two };
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int row[2] = { Cur[0].row + DELPos[i][0], Cur[1].row + DELPos[i][0] };
            int col[2] = { Cur[0].col + DELPos[i][1], Cur[1].col + DELPos[i][1] };
            int dir[2] = { Cur[0].dir, Cur[1].dir };
            int time = Cur[0].time;

            Point Next[2] = { {row[0],col[0],dir[0],time + 1},
                            {row[1],col[1],dir[1],time + 1} };

            if (!isValid(Next))
                continue;

            for (int j = 0; j < 2; j++) {
                if (Next[j].col == N - 1 && Next[j].row == N - 1) {
                    answer = Next[j].time;
                    return;
                }

                //방문
                visit[row[j]][col[j]][dir[j]] = true;
            }

            Q.push({ Next[0],Next[1] });
        }

        //회전 역,정
        for (int i = 0; i < 2; i++) {

            //회전축
            for (int j = 0; j < 2; j++) {

                if (rotate(Cur, i, j))
                    return;
            }
        }
    }

    return;
}

int solution(vector<vector<int>> board) {
    Board = board;
    N = board.size();

    MoveRobo();

    return answer;
}