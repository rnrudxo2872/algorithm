#include<bits/stdc++.h>
#define INF 99999999
#define MaxNode 201

using namespace std;

int Dist[MaxNode][MaxNode];
int N;

void init() {
    for (int i = 0; i <= N; i++) {

        for (int j = 0; j <= N; j++)
            Dist[i][j] = INF;
        Dist[i][i] = 0;
    }
}

void Floyd_Warshall() {
    for (int mid = 1; mid <= N; mid++) {
        for (int From = 1; From <= N; From++) {
            for (int To = 1; To <= N; To++) {

                if (From == To || From == mid || mid == To)
                    continue;

                if (Dist[From][mid] == INF || Dist[mid][To] == INF)
                    continue;

                // 지점간 최소거리를 갱신
                if (Dist[From][To] > Dist[From][mid] + Dist[mid][To])
                    Dist[From][To] = Dist[From][mid] + Dist[mid][To];

            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    int answer = 0;

    //거리값 초기화
    init();

    //그래프간 거리 갱신
    for (int i = 0; i < fares.size(); i++) {
        int From = fares[i][0];
        int To = fares[i][1];
        int Cost = fares[i][2];

        Dist[From][To] = Cost;
        Dist[To][From] = Cost;
    }

    Floyd_Warshall();

    answer = Dist[s][a] + Dist[s][b];

    for (int i = 1; i <= N; i++) {
        if (Dist[s][i] == INF || Dist[i][a] == INF || Dist[i][b] == INF)
            continue;

        answer = answer < Dist[s][i] + Dist[i][a] + Dist[i][b] ? answer : Dist[s][i] + Dist[i][a] + Dist[i][b];
    }

    return answer;
}