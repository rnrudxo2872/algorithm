#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visit[500001] = { 0, };

int solution(std::vector<int> a) {
    int answer = 0;
    if (a.size() <= 1)
        return 0;
    for (int i = 0; i < a.size(); i++) { // 숫자 종류 파악
        visit[a[i]] += 1;
    }

    for (int i = 0; i <= a.size(); i++) {
        if (!visit[i]) // 숫자가 존재하지 않는다면 넘긴다.
            continue;
        if (visit[i] <= answer) // 시간초과로 추가한 조건문, 지금 최대값보다 작은 갯수의 스타수열은 안봐도 된다.
            continue;
        int cnt = 0;
        for (int j = 0; j < a.size() - 1; j++) { //이 숫자가 포함된 스타수열의 길이를 찾는다.
            if ((a[j] != a[j + 1]) && (a[j] == i || a[j+1] == i)) {
                cnt++;
                j++; // 스타수열이면!! 한개씩 짝지어 index는 2칸씩 이동해야한다.
            }
        }
        answer = answer > cnt ? answer : cnt;
    }
    answer *= 2;
    return answer;
}

int main() {
    cout << solution({ 4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3 }) << endl;
}