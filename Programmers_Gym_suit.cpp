#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int ans = n - lost.size(); // �������ϰų� ���� ����� ����
    bool visit[31] = { 0, };

    int cnt = 0; // ü������ ���� ��� ��.
    for (int i = 0; i < lost.size(); i++) { // ������������ �������� �ִ� ���.
        for (int j = 0; j < reserve.size(); j++) {
            if (visit[reserve[j]])
                continue;
            if (lost[i] == reserve[j]) {
                int res = reserve[j];
                cnt++;
                visit[res] = true;
                visit[lost[i]] = true;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            int los = lost[i];
            int res = reserve[j];

            if (visit[los])
                break;
            if (visit[res])
                continue;
            if (los - 1 == res) {
                cnt++;
                visit[res] = true;
                visit[los] = true;
            }
            else if (los + 1 == res) {
                cnt++;
                visit[res] = true;
                visit[los] = true;
            }
        }
    }

    ans += cnt;
    return ans;
}