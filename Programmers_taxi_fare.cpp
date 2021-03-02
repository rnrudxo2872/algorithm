#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define INF 99999999

int dist[201][201];

void floyd_warshall(int n) {
    for (int i = 1; i <= n; i++) { //중간지점
        for (int j = 1; j <= n; j++) { // 시작점
            for (int k = 1; k <= n; k++) { // 도착점
                if (i == j || j == k || k == i)
                    continue;
                if (dist[j][i] != INF && dist[i][k] != INF && dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    fill(&dist[0][0], &dist[200][201], INF);

    for (int i = 0; i < fares.size(); i++) { //dist 초기화
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int i = 1; i <= n; i++) // 자기자신 거리  !!! 중요. 자주 실수 !!!
        dist[i][i] = 0;

    floyd_warshall(n);

    answer = dist[s][a] + dist[s][b];

    for (int i = 1; i <= n; i++) {
        if (dist[s][i] != INF && dist[i][a] != INF && dist[i][b] != INF)
            answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }

    return answer;
}