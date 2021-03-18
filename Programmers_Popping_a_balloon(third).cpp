#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> arr[1000001];

int solution(vector<int> a) {
    int answer = 0;

    for (int i = 0; i < a.size(); i++) {
        arr[i] = { a[i],i }; // value, index
    }

    sort(arr, arr + a.size()); // 오름차순 정렬

    int Min = arr[1].second > arr[0].second ? arr[0].second : arr[1].second; // 최소값 인덱스
    int Max = arr[1].second > arr[0].second ? arr[1].second : arr[0].second; // 최소 2순위 인덱스

    for (int i = 2; i < a.size(); i++) {
        int Cur_value = arr[i].first;
        int Cur_index = arr[i].second;

        if (Min < Cur_index && Cur_index < Max) // 현재값이 범위 안에 있을 때, 풍선은 살아남을수 없다.
            continue;
        Min = Cur_index < Min ? Cur_index : Min;
        Max = Cur_index > Max ? Cur_index : Max;
        answer++; //살아남았다.
    }

    answer += 2; // 최소 1, 2 순위인 풍선들은 default로 넣어준다.
    return answer;
}