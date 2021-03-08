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

    vector<Ballon> v(size, { 0,0 }); // vector �ʱⰪ

    for (int i = 0; i < size; i++) { // ǳ���� ���� index�� v�� �־�д�.
        v[i].weight = a[i];
        v[i].index = i;
    }
    sort(v.begin(), v.end(), cmp); // ��������

    int index1 = v[0].index > v[1].index ? v[1].index : v[0].index; // ���� ���� ���� index
    int index2 = v[0].index > v[1].index ? v[0].index : v[1].index; // 2���� index

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