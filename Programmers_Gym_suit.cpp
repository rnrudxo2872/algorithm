#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int ans = n - lost.size(); // 도난당하거나 없는 사람을 제외
    bool visit[31] = { 0, };

    int cnt = 0; // 체육복을 얻은 사람 수.
    for (int i = 0; i < lost.size(); i++) { // 도난당했지만 여유분이 있는 사람.
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