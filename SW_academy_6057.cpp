#include<iostream>

using namespace std;

bool visit[51];
int map[51][51] = { 0, };
int ans = 0;
int N;

void dfs(int start, int depth, int cur) {
    if (depth == 2) {
        if (start == cur) {
            ans++;
        }

    }
    else {
        for (int i = 1; i <= N; i++) {
            if (!visit[i] && map[cur][i]) {
                visit[i] = true;
                dfs(start, depth + 1, i);
                visit[i] = false;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        ans = 0;
        int M;
        scanf_s("%d %d", &N, &M);
        for (int i = 1; i <= N; i++) {
            visit[i] = false;
            for (int j = 1; j <= N; j++)
                map[i][j] = 0;
        }
        for (int i = 0; i < M; i++) {
            int x, y;
            scanf_s("%d %d", &x, &y);
            map[x][y] += 1;
            map[y][x] += 1;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (j < i)
                    visit[j] = true;
                else
                    visit[j] = false;
            }
            for (int j = 1; j <= N; j++) {

                if (!visit[j] && map[i][j]) {
                    visit[j] = true;
                    dfs(i, 0, j);
                }
            }
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}