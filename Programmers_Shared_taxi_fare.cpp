#include <vector>
#include <iostream>
#define INF 9999999

using namespace std;

int dist[201][201] = { 0, };

void floyd(int n) {
    for (int k = 1; k <= n; k++) { // 중간
        for (int i = 1; i <= n; i++) { // 시작
            for (int j = 1; j <= n; j++) { // 끝

                if (i == j && i == k && j == k)
                    continue;
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            dist[i][j] = INF;
        dist[i][i] = 0;
    }


    for (int i = 0; i < fares.size(); i++) { // 초기 거리 갱신
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];

        dist[from][to] = cost;
        dist[to][from] = cost;
    }

    floyd(n);

    int route = dist[s][a] + dist[s][b]; // 둘이 따로 갈 때,

    for (int i = 1; i <= n; i++) {
        int Cur = dist[s][i] + dist[i][a] + dist[i][b];
        if (dist[s][i] != INF && dist[i][a] != INF && dist[i][b] != INF && Cur < route)
            route = Cur < route ? Cur : route;
    }
    answer = route;

    return answer;
}

int main() {
    cout << solution(6, 4, 5, 6, { {2, 6, 6},{6, 3, 7},{4, 6, 7},{6, 5, 11},{2, 5, 12},{5, 3, 20},{2, 4, 8},{4, 3, 9} }) << endl;
}