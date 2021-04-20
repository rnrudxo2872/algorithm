#include <bits/stdc++.h>
#define Max 22

using namespace std;

int R, C;
int ans;
char Map[Max][Max] = { 0, };
int DelPoint[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}, };
bool Visit[Max][Max] = { 0, };
bool Alpha[26] = { 0, };

struct Point {
    int r;
    int c;
};

void init() {
    ios::sync_with_stdio(false);
    cin.tie();
}

void dfs(int cnt, Point Cur) {
    if (cnt > ans)
        ans = cnt;

    for (int i = 0; i < 4; i++) {
        int r = Cur.r + DelPoint[i][0];
        int c = Cur.c + DelPoint[i][1];
        int alpha = Map[r][c] - 'A';

        if (Alpha[alpha])
            continue;

        if (Visit[r][c] || R - 1 < r || r < 0 || C - 1 < c || c < 0)
            continue;

        Visit[r][c] = true;
        Alpha[alpha] = true;
        dfs(cnt + 1, { r,c });
        Visit[r][c] = false;
        Alpha[alpha] = false;
    }
}

int main() {
    init();
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < C; j++)
            Map[i][j] = temp[j];
    }

    Point Cur = { 0,0 };
    Visit[0][0] = true;

    int alpha = Map[0][0] - 'A';
    Alpha[alpha] = true;

    //말을 움직인다
    dfs(1, Cur);

    printf("%d", ans);
}