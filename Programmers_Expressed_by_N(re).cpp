#include<bits/stdc++.h>
#define INF 99999999

using namespace std;

int target;
int minCnt = INF;

void dfs(int N, int cnt, int curNum) {
    if (cnt > 8)
        return;
    if (curNum == target) {
        minCnt = minCnt < cnt ? minCnt : cnt;
        return;
    }

    //연산할 값, 초기 0
    int funcNum = 0;

    //depth를 연산해줄 loop
    for (int i = 1; i < 10; i++) {
        funcNum = funcNum * 10 + N;

        dfs(N, cnt + i, curNum + funcNum);
        dfs(N, cnt + i, curNum - funcNum);

        if (curNum != 0) {
            dfs(N, cnt + i, curNum * funcNum);
            dfs(N, cnt + i, curNum / funcNum);
        }
    }
}

int solution(int N, int number) {
    int answer = 0;

    target = number;

    dfs(N, 0, 0);

    answer = minCnt > 8 ? -1 : minCnt;
    return answer;
}