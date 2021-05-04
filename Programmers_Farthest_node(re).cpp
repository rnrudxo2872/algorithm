#include<bits/stdc++.h>
#define MAX 20001

using namespace std;

struct node {
    int num;
    int cnt;
};

vector<int> v[MAX];
queue<node> Q;
bool Visit[MAX] = { 0, };
int maxTime = 0;
int longestCnt = 0;

void findNodes() {
    while (!Q.empty()) {
        int curNode = Q.front().num;
        int curTime = Q.front().cnt;
        Q.pop();

        if (maxTime == curTime)
            longestCnt++;
        if (maxTime < curTime) {
            maxTime = curTime;
            longestCnt = 1;
        }

        for (int i = 0; i < v[curNode].size(); i++) {
            int nNode = v[curNode][i];

            if (Visit[nNode])
                continue;

            Visit[nNode] = true;
            Q.push({ nNode,curTime + 1 });
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    Q.push({ 1,0 });
    Visit[1] = true;

    for (int i = 0; i < edge.size(); i++) {
        int p1 = edge[i][0];
        int p2 = edge[i][1];

        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }

    findNodes();

    return longestCnt;
}