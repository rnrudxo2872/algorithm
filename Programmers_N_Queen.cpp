#include <vector>
#include <math.h>

using namespace std;

bool visit[13] = { 0, };
int index[13] = { 0, };
int answer = 0;

/*
abs(x1 - x2) == abs(y1 - y2) => 대각선상에 있다는 것. - 제외
*/

void dfs(int depth, int n) {
    if (depth == n + 1) { // n포함 해야하기에  +1까지 온게 답이다.
        answer += 1;
        return;
    }

    for (int i = 1; i <= n; i++) { //y 축 탐색
        if (visit[i])
            continue;
        bool possible = true;
        for (int j = 1; j < depth; j++) {
            if (abs(i - index[j]) == abs(depth - j)) {
                possible = false;
                break;
            }
        }
        if (!possible)
            continue;
        visit[i] = true;
        index[depth] = i;
        dfs(depth + 1, n);
        index[depth] = 0;
        visit[i] = false;
    }
}


int solution(int n) {

    dfs(1, n);
    return answer;
}