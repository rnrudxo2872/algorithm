#include<bits/stdc++.h>

using namespace std;

struct Struct {
    bool Tower;
    bool Bo;
};

Struct Map[104][104] = { 0, };
int N;

bool isValidTower(int X, int Y) {
    //바닥위에 경우
    if (Y == 0)
        return true;

    //다른 기둥 위
    if (Y - 1 >= 0 && Map[Y - 1][X].Tower)
        return true;

    //다른 보 끝 위에 있을지
    if (X - 1 >= 0 && Map[Y][X - 1].Bo)
        return true;

    if(X < N && Map[Y][X].Bo)
        return true;

    //그 외
    return false;
}

bool isValidBo(int X, int Y) {

    //한쪽 끝 부분이 기둥위에 있다면
    if (Y > 0 && X <N && Map[Y - 1][X + 1].Tower || Map[Y - 1][X].Tower)
        return true;

    if (X > 0 && X < N && Map[Y][X - 1].Bo && Map[Y][X + 1].Bo)
        return true;

    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;


    for (vector<int> cmd : build_frame) {
        int X = cmd[0];
        int Y = cmd[1];
        int Item = cmd[2];
        int IORR = cmd[3];

        //설치
        if (IORR) {

            //우선적으로 설치

            //기둥 설치
            if (Item == 0) {

                //확인
                if (isValidTower(X, Y))
                    Map[Y][X].Tower = true;
            }

            //보 설치
            else {

                //확인
                if (isValidBo(X, Y))
                    Map[Y][X].Bo = true;

            }
        }

        //삭제
        else {

            //기둥 삭제
            if (Item == 0) {
                bool posi = true;
                Map[Y][X].Tower = false;

                //만약 위에 왼쪽에서 오는 보가 있다면
                if (Y < n && Map[Y + 1][X].Bo && !isValidBo(X, Y + 1))
                    posi = false;

                //만약 위에 오른쪽에 오는 보가 있다면
                if (X - 1 >= 0 && Map[Y + 1][X - 1].Bo && !isValidBo(X - 1, Y + 1))
                    posi = false;
                
                //만약 위에 기둥이 있다면
                if (Y < n && Map[Y + 1][X].Tower && !isValidTower(X, Y + 1))
                    posi = false;

                if(!posi)
                    Map[Y][X].Tower = true;
            }

            //보 삭제
            else {
                bool posi = true;
                Map[Y][X].Bo = false;

                //왼쪽에 보가 있다면
                if (X - 1 >= 0 && Map[Y][X - 1].Bo && !isValidBo(X - 1, Y))
                    posi = false;

                //오른쪽에 보가 있다면
                if (X < n && Map[Y][X + 1].Bo && !isValidBo(X + 1, Y))
                    posi = false;

                //보 위에 기둥이 있다면
                if (Map[Y][X].Tower && !isValidTower(X, Y))
                    posi = false;

                if (Map[Y][X + 1].Tower && !isValidTower(X + 1, Y))
                    posi = false;

                if (!posi)
                    Map[Y][X].Bo = true;
            }
        }

    }

    for (int j = 0; j < n + 1; j++) {
        for (int i = 0; i < n + 1; i++) {
            if (Map[i][j].Tower)
                answer.push_back({ j,i,0 });

            if (Map[i][j].Bo)
                answer.push_back({ j,i,1 });
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return answer;
}