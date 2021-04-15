#include<bits/stdc++.h>

using namespace std;

struct Struct {
    bool Tower;
    bool Bo;
};

Struct Map[104][104] = { 0, };
int N;

bool isValidTower(int X, int Y) {
    //�ٴ����� ���
    if (Y == 0)
        return true;

    //�ٸ� ��� ��
    if (Y - 1 >= 0 && Map[Y - 1][X].Tower)
        return true;

    //�ٸ� �� �� ���� ������
    if (X - 1 >= 0 && Map[Y][X - 1].Bo)
        return true;

    if(X < N && Map[Y][X].Bo)
        return true;

    //�� ��
    return false;
}

bool isValidBo(int X, int Y) {

    //���� �� �κ��� ������� �ִٸ�
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

        //��ġ
        if (IORR) {

            //�켱������ ��ġ

            //��� ��ġ
            if (Item == 0) {

                //Ȯ��
                if (isValidTower(X, Y))
                    Map[Y][X].Tower = true;
            }

            //�� ��ġ
            else {

                //Ȯ��
                if (isValidBo(X, Y))
                    Map[Y][X].Bo = true;

            }
        }

        //����
        else {

            //��� ����
            if (Item == 0) {
                bool posi = true;
                Map[Y][X].Tower = false;

                //���� ���� ���ʿ��� ���� ���� �ִٸ�
                if (Y < n && Map[Y + 1][X].Bo && !isValidBo(X, Y + 1))
                    posi = false;

                //���� ���� �����ʿ� ���� ���� �ִٸ�
                if (X - 1 >= 0 && Map[Y + 1][X - 1].Bo && !isValidBo(X - 1, Y + 1))
                    posi = false;
                
                //���� ���� ����� �ִٸ�
                if (Y < n && Map[Y + 1][X].Tower && !isValidTower(X, Y + 1))
                    posi = false;

                if(!posi)
                    Map[Y][X].Tower = true;
            }

            //�� ����
            else {
                bool posi = true;
                Map[Y][X].Bo = false;

                //���ʿ� ���� �ִٸ�
                if (X - 1 >= 0 && Map[Y][X - 1].Bo && !isValidBo(X - 1, Y))
                    posi = false;

                //�����ʿ� ���� �ִٸ�
                if (X < n && Map[Y][X + 1].Bo && !isValidBo(X + 1, Y))
                    posi = false;

                //�� ���� ����� �ִٸ�
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