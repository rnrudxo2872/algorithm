#include <bits/stdc++.h>
#define MaxFire 2501
#define MaxBoard 51

using namespace std;

//���̾ �ϳ��� ������ ��ǥ�� ����, �ӵ�, ����
struct Fire {
    int row;
    int col;
    int m;
    int speed;
    int dir;
};

int N, M, K;
int delPos[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
vector<Fire> Arr;
vector<Fire> Map[MaxBoard][MaxBoard];

void init() {
    ios::sync_with_stdio(false);
    cout.tie(); cin.tie();
}

void moveFire() {
    //�� �ش� ��ǥ�� ���̾ ����
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Map[i][j].clear();
        }
    }

    for (int i = 0; i < Arr.size(); i++) {
        int dir = Arr[i].dir;
        int speed = Arr[i].speed % N;
        int row = Arr[i].row + (speed * delPos[dir][0]);
        int col = Arr[i].col + (speed * delPos[dir][1]);

        if (row > N) row -= N;
        if (col > N) col -= N;
        if (row < 1) row += N;
        if (col < 1) col += N;

        Map[row][col].push_back({ row,col,Arr[i].m,speed,dir });
    }
}
void divFir() {
    vector<Fire> tem;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int pointSize = Map[i][j].size();

            if (pointSize == 0)
                continue;
            if (pointSize == 1) {
                tem.push_back(Map[i][j][0]);
                continue;
            }

            bool odd = true;
            bool pair = true;
            int sumMassive = 0;
            int sumSpeed = 0;

            for (int k = 0; k < pointSize; k++) {
                sumMassive += Map[i][j][k].m;
                sumSpeed += Map[i][j][k].speed;
                
                //Ȧ¦ �Ǻ�
                if (Map[i][j][k].dir % 2 != 0)
                    pair = false;
                else
                    odd = false;
            }
            int insertMass = sumMassive / 5;
            int insertSpeed = sumSpeed / pointSize;
            
            //���� ������ ���԰� 0�̶��, �����
            if (!insertMass)
                continue;

            if (odd || pair) {
                for (int q = 0; q < 8; q += 2)
                    tem.push_back({ i,j,insertMass,insertSpeed,q });
            }
            else {
                for (int q = 1; q < 8; q += 2)
                    tem.push_back({ i,j,insertMass, insertSpeed,q });
            }
        }
    }
    Arr = tem;
}

int main() {
    init();

    //���� ũ��, ��ɾ� ����, �̵� ��� Ƚ��
    cin >> N >> M >> K;

    //��ɾ� ����
    for (int i = 0; i < M; i++) {
        int row, col, m, speed, dir;
        cin >> row >> col >> m >> speed >> dir;
        
        Arr.push_back({ row,col,m,speed,dir });
    }

    for (int i = 0; i < K; i++) {
        moveFire();
        divFir();
    }

    int answer = 0;
    for (int i = 0; i < Arr.size(); i++) {
        answer += Arr[i].m;
    }
    printf("%d", answer);
}