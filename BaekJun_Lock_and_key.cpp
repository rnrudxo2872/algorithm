#include <string>
#include <vector>
#define M 63

using namespace std;

int Map[M][M];
vector<vector<int>> Key;
vector<vector<int>> Lock;

// Key 시계방향 90도 회전
void rotate() {
    int row = Key.size();
    int col = row;
    vector<vector<int>> temp;
    temp.resize(row, vector<int>(col));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            temp[i][j] = Key[col - 1 - j][i];
    Key = temp;
}

bool Check(int Y, int X) {
    int CurRow = 0;
    int CurCol = 0;

    int temMap[M][M] = { 0, };
    int Size = Key.size() - 1;

    for (int i = Y; i <= Y + Size; i++) {
        for (int j = X; j <= X + Size; j++) {
            temMap[i][j] += Key[CurRow][CurCol];

            CurCol++;
        }
        CurCol = 0;
        CurRow++;
    }


    CurRow = 0;
    CurCol = 0;
    for (int i = Size; i < Size + Lock.size(); i++) {
        for (int j = Size; j < Size + Lock.size(); j++) {
            temMap[i][j] += Lock[CurRow][CurCol];
            if (temMap[i][j] > 1) {
                return false;
            }

            CurCol++;
        }
        CurCol = 0;
        CurRow++;
    }
    /*for (int i = 0; i < 41; i++) {
        for (int j = 0; j < 41; j++) {
            cout << temMap[i][j] << " ";
        }
        cout << endl;
    }*/
    for (int i = Size; i < Size + Lock.size(); i++) {
        for (int j = Size; j < Size + Lock.size(); j++) {

            if (temMap[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool SearchMap() {
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < Key.size() - 1 + Lock.size(); i++) {
            for (int j = 0; j < Key.size() - 1 + Lock.size(); j++) {
                if (Check(i, j)) {
                    return true;
                }
            }
        }
        rotate();
    }
    return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    Key = key;
    Lock = lock;

    answer = SearchMap();


    return answer;
}