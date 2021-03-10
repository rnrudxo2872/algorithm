#include <string>
#include <vector>

using namespace std;
#define Max 101

bool visit[Max][Max] = { 0, };
vector<int> Win[Max]; //선수가 이긴 선수들
vector<int> Lose[Max]; //선수가 진 선수들

void Make_connect(int winner, int loser) {
    for (int i = 0; i < Win[loser].size(); i++) {
        int another = Win[loser][i];

        if (!visit[another][winner]) {
            visit[winner][another] = true;
            visit[another][winner] = true;
            Make_connect(winner, another);
            Win[winner].push_back(another);
            Lose[another].push_back(winner);
        }
    }

    for (int i = 0; i < Lose[winner].size(); i++) {
        int another = Lose[winner][i];

        if (!visit[another][loser]) {
            visit[loser][another] = true;
            visit[another][loser] = true;
            Make_connect(another, loser);
            Lose[loser].push_back(another);
            Win[another].push_back(loser);
        }
    }
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
        visit[i][i] = true;

    for (int i = 0; i < results.size(); i++) {
        int Winner = results[i][0];
        int Loser = results[i][1];

        if (!visit[Winner][Loser]) {
            visit[Winner][Loser] = true;
            visit[Loser][Winner] = true;
            Make_connect(Winner, Loser); // 
            Win[Winner].push_back(Loser);
            Lose[Loser].push_back(Winner);

        }
    }
    for (int i = 1; i <= n; i++) {
        int sizeOfWin = Win[i].size();
        int sizeOfLose = Lose[i].size();
        if (sizeOfLose + sizeOfWin == n - 1)
            answer++;
    }

    return answer;
}