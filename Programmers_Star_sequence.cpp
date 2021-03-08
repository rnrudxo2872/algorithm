#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = -1;
    int size = a.size();
    vector<int> Cnt(a.size(), 0);


    for (int i = 0; i < size; i++)
        Cnt[a[i]] += 1; // 숫자가 나온 횟수

    for (int i = 0; i < Cnt.size(); i++) {
        int CurNum = Cnt[i];
        if (answer >= CurNum || CurNum == 0)
            continue;
        int dumCnt = 0;

        for (int k = 0; k < size - 1; k++) {
            if (a[k + 1] == a[k])
                continue;
            if (i != a[k] && i != a[k + 1])
                continue;
            k++;
            dumCnt++;
        }
        answer = answer > dumCnt ? answer : dumCnt;
    }
    answer *= 2;
    return answer;
}