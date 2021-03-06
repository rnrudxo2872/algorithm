#include <algorithm>
#include <vector>
#define Max 1000001

using namespace std;

struct Ballon {
    int num;
    int index;
};

bool cmp(Ballon& a, Ballon& b) {
    if (a.num < b.num)
        return true;
    else if (a.num == b.num)
        return a.index < b.index;
    return false;
}

Ballon arr[Max] = { 0, };

int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    if (size <= 2)
        return size;

    for (int i = 0; i < size; i++) {
        arr[i].num = a[i];
        arr[i].index = i;
    }
    sort(arr, arr + size, cmp);

    int index = arr[0].index < arr[1].index ? arr[0].index : arr[1].index; // 제일 작은 숫자와
    int index2 = arr[0].index > arr[1].index ? arr[0].index : arr[1].index; // 2순위로 작은 숫자.

    for (int i = 2; i < size; i++) {
        int Cur_index = arr[i].index;

        if (index < Cur_index && Cur_index < index2)
            continue;
        index = index > Cur_index ? Cur_index : index;
        index2 = index2 < Cur_index ? Cur_index : index2;
        ++answer;
    }

    answer += 2;
    return answer;
}