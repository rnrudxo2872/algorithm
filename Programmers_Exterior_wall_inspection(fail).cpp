#include <vector>
#include <algorithm>
#include <iostream>

#define INF 99999

using namespace std;

int N, Size;
int Min = INF;
vector<int> Weak;
vector<int> Dist;
bool visit[20100];

void FunSolve(int start, int Friend) {
    if (Friend > Dist.size())
        return;
    if (Friend >= Min)
        return;

    int WeakSize = Weak.size();
    for (int i = 0; i < WeakSize; i++) {

        int Next = (start + i) % WeakSize;
        int diff = Weak[Next] - Weak[start];

        if (diff < 0)
            diff += N;
        if (diff > Dist[Dist.size() - Friend])
            break;

        if (!visit[Next])
            Size += 1;
        visit[Next] = true;
    }

    if (Size == WeakSize) {
        Min = Friend;
        return;
    }
    for (int i = 0; i < WeakSize; i++) {
        if (visit[i])
            continue;
        visit[i] = true;
        Size++;
        FunSolve(i, Friend + 1);
        Size--;
        visit[i] = false;
    }

}

int solution(int n, vector<int> weak, vector<int> dist) {
    int WeakSize = weak.size();
    sort(dist.begin(), dist.end());
    N = n;
    Weak = weak;
    Dist = dist;

    for (int i = 0; i < WeakSize; i++) {
        visit[i] = true;
        Size = 1;
        FunSolve(i, 1);
        fill(visit, visit + 2000, 0);
    }
    if (Min == INF)
        return -1;

    return Min;
}

int main() {
    cout << solution(30, { 0, 3, 11, 21 }, { 10, 4 });
}