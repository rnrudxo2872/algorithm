#include <string>
#include <vector>
#include <algorithm>
#define INF 99999

using namespace std;

vector<int> Weak;
vector<int> Dist;
int N;
int Min = INF;

void Search(int Start, int Friend, int visit) {
    
    // 친구 카운팅이 인원수를 넘어간다면,
    if (Friend > Dist.size())
        return;

    // 최소값 이상으로 인원이 투입된다면,
    if (Friend >= Min)
        return;

    for (int i = 0; i < Weak.size(); i++) {

        int Next = (Start + i) % Weak.size();
        int diff = Weak[Next] - Weak[Start];

        // Next가 기준 Idx(원점)이 지났다면,
        if (diff < 0)
            diff += N;

        // 현재 친구가 갈 수 있는 거리를 넘어선다면,
        if (diff > Dist[Dist.size() - Friend])
            break;

        // 방문체크
        visit |= 1 << Next;
    }

    // 모든 벽을 보수했다면,
    if (visit == (1 << Weak.size()) - 1) {
        Min = Min < Friend ? Min : Friend;
        return;
    }

    for (int i = 0; i < Weak.size(); i++) {

        // 해당 Idx를 방문했다면,
        if (visit & (1 << i))
            continue;

        Search(i, Friend + 1, visit);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {

    N = n;
    Weak = weak;
    Dist = dist;

    // 친구들 오름차순 정렬
    sort(dist.begin(), dist.end());

    for (int i = 0; i < weak.size(); i++) {

        // 보수공사 모든 위치를 시작점에 첫번째 친구를 모두 넣는다.
        Search(i, 1, 0);
    }

    // Min이 갱신되지 않았다면,
    if (Min == INF)
        return -1;

    return Min;
}