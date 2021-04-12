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
    
    // ģ�� ī������ �ο����� �Ѿ�ٸ�,
    if (Friend > Dist.size())
        return;

    // �ּҰ� �̻����� �ο��� ���Եȴٸ�,
    if (Friend >= Min)
        return;

    for (int i = 0; i < Weak.size(); i++) {

        int Next = (Start + i) % Weak.size();
        int diff = Weak[Next] - Weak[Start];

        // Next�� ���� Idx(����)�� �����ٸ�,
        if (diff < 0)
            diff += N;

        // ���� ģ���� �� �� �ִ� �Ÿ��� �Ѿ�ٸ�,
        if (diff > Dist[Dist.size() - Friend])
            break;

        // �湮üũ
        visit |= 1 << Next;
    }

    // ��� ���� �����ߴٸ�,
    if (visit == (1 << Weak.size()) - 1) {
        Min = Min < Friend ? Min : Friend;
        return;
    }

    for (int i = 0; i < Weak.size(); i++) {

        // �ش� Idx�� �湮�ߴٸ�,
        if (visit & (1 << i))
            continue;

        Search(i, Friend + 1, visit);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {

    N = n;
    Weak = weak;
    Dist = dist;

    // ģ���� �������� ����
    sort(dist.begin(), dist.end());

    for (int i = 0; i < weak.size(); i++) {

        // �������� ��� ��ġ�� �������� ù��° ģ���� ��� �ִ´�.
        Search(i, 1, 0);
    }

    // Min�� ���ŵ��� �ʾҴٸ�,
    if (Min == INF)
        return -1;

    return Min;
}