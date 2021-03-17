#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end()); // greed탐색을 위해 오름차순으로 정렬한다.

    int optimal = routes[0][1]; //카메라를 설치할 최적의 위치인 끝자리로 설정

    for (int i = 0; i < routes.size(); i++) {
        int Start = routes[i][0];
        int End = routes[i][1];
        if (Start > optimal) { //최적 위치 카메라 범위 밖일 때,
            answer++;
            optimal = End;
        }
        if (End < optimal) //이전 route보다 범위가 작은 구간을 만났을 때, 다시 최적 위치에 카메라를 재설정
            optimal = End;
    }

    return answer;
}