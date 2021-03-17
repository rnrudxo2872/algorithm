#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end()); // greedŽ���� ���� ������������ �����Ѵ�.

    int optimal = routes[0][1]; //ī�޶� ��ġ�� ������ ��ġ�� ���ڸ��� ����

    for (int i = 0; i < routes.size(); i++) {
        int Start = routes[i][0];
        int End = routes[i][1];
        if (Start > optimal) { //���� ��ġ ī�޶� ���� ���� ��,
            answer++;
            optimal = End;
        }
        if (End < optimal) //���� route���� ������ ���� ������ ������ ��, �ٽ� ���� ��ġ�� ī�޶� �缳��
            optimal = End;
    }

    return answer;
}