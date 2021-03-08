#include <vector>
#include <algorithm>

using namespace std;

struct Ballon {
    int weight;
    int index;
};

bool cmp(Ballon& a, Ballon& b) {
    if (a.weight < b.weight)
        return true;
    else if (a.weight == b.weight)
        return a.index < b.index;
    return false;
}


int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    if (size <= 2)
        return size;

    vector<Ballon> v(size, { 0,0 }); // vector 초기값

    for (int i = 0; i < size; i++) { // 풍선의 값과 index를 v에 넣어둔다.
        v[i].weight = a[i];
        v[i].index = i;
    }
    sort(v.begin(), v.end(), cmp); // 오름차순

    int index1 = v[0].index > v[1].index ? v[1].index : v[0].index; // 값이 제일 작은 index
    int index2 = v[0].index > v[1].index ? v[0].index : v[1].index; // 2순위 index

    for (int i = 2; i < size; i++) {
        int CurNum = v[i].index;

        if (index1 < CurNum && CurNum < index2)
            continue;
        index1 = index1 < CurNum ? index1 : CurNum;
        index2 = CurNum < index2 ? index2 : CurNum;
        answer++;
    }
    answer += 2;
    return answer;
}