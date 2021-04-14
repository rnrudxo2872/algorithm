#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define Up 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

struct Point {
    int row, col;
    int dir;
    int time;
};

struct Robo {
    Point one;
    Point two;
};

int N;
int answer = 0;
vector<vector<int>> Board;
bool visit[100][100][4] = { 0, };
queue<Robo> qu;

int DelPos[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int Delrot[2][4][2] = { {{1,-1},{-1,-1},{-1,1},{1,1 }},
                        {{1,1},{1,-1},{-1,-1},{-1,1 }} };
int Cornor[2][4][2] = { {{-1,-1},{-1,1},{1,1},{1,-1}},
                        {{-1,1},{1,1},{1,-1},{-1,-1}} };

// 유효 검사
bool isValid(Point some[2]) {
    for (int i = 0; i < 2; i++) {
        int row = some[i].row;
        int col = some[i].col;
        int dir = some[i].dir;

        if (N <= col || col < 0 || N <= row || row < 0)
            return false;
        if (Board[row][col])
            return false;
        if (visit[row][col][dir])
            return false;
    }
    return true;
}

int rotate(Point some[2], int Cdir, int fix) {

    Point Next[2];
    int A = fix;
    int B = (fix + 1) % 2;

    int Acol = some[A].col, Arow = some[A].row, Adir = some[A].dir, Atime = some[A].time;
    int Bcol = some[B].col, Brow = some[B].row, Bdir = some[B].dir, Btime = some[B].time;

    //1일 땐, 정방향
    Next[0] = { Arow,Acol,(Adir + (Cdir ? 1 : 3)) % 4,Atime + 1 };
    Next[1] = { Brow + Delrot[Cdir][Adir][0], Bcol + Delrot[Cdir][Adir][1], (Bdir + (Cdir ? 1 : 3)) % 4, Btime + 1 };

    if (!isValid(Next))
        return 0;
    
    if (Board[some[A].row + Cornor[Cdir][Adir][0]][some[A].col + Cornor[Cdir][Adir][1]] == 1)
        return 0;

    for (int i = 0; i < 2; i++) {
        if (Next[i].row == N - 1 && Next[i].col == N - 1)
            return Next[i].time;

        visit[Next[i].row][Next[i].col][Next[i].dir] = true;
    }

    qu.push({ Next[0],Next[1] });
    return 0;
}

void MoveRobo() {
    qu.push({{ 0,0,RIGHT,0 }, { 0,1,LEFT,0 } });
    visit[0][0][RIGHT] = true;
    visit[0][1][LEFT] = true;
    
    while (!qu.empty()) {
        Point Cur[2] = { qu.front().one,qu.front().two };
        qu.pop();

        int row[2] = { Cur[0].row,Cur[1].row };
        int col[2] = { Cur[0].col, Cur[1].col };
        int dir[2] = { Cur[0].dir, Cur[1].dir };
        int time[2] = { Cur[0].time,Cur[1].time };
        
        // 좌표이동 시,
        for (int i = 0; i < 4; i++) {
            Point Next[2] = { { row[0] + DelPos[i][0],col[0] + DelPos[i][1],dir[0],time[0] + 1 }, 
                            { row[1] + DelPos[i][0],col[1] + DelPos[i][1],dir[1],time[1] + 1 } };

            if (!isValid(Next))
                continue;
            
            for (int i = 0; i < 2; i++) {
                if (Next[i].col == N - 1 && Next[i].row == N - 1) {
                    answer = Next[i].time;
                    return;
                }
                visit[Next[i].row][Next[i].col][Next[i].dir] = true;
            }
            qu.push({ Next[0],Next[1] });
        }
        
        // 회전 시, 시계방향과 반시계방향
        for (int i = 0; i < 2; i++) {

            // 어느 포인트가 회전축일지
            for (int j = 0; j < 2; j++) {
                int Re = rotate(Cur, i, j);
                if (Re) {
                    answer = Re;
                    return;
                }
                
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    Board = board;
    N = board.size();

    MoveRobo();

    return answer;
}

int main() {
    cout << solution({ {0, 0, 0, 1, 1} ,{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} });
}