#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> arr[1000001];

int solution(vector<int> a) {
    int answer = 0;

    for (int i = 0; i < a.size(); i++) {
        arr[i] = { a[i],i }; // value, index
    }

    sort(arr, arr + a.size()); // �������� ����

    int Min = arr[1].second > arr[0].second ? arr[0].second : arr[1].second; // �ּҰ� �ε���
    int Max = arr[1].second > arr[0].second ? arr[1].second : arr[0].second; // �ּ� 2���� �ε���

    for (int i = 2; i < a.size(); i++) {
        int Cur_value = arr[i].first;
        int Cur_index = arr[i].second;

        if (Min < Cur_index && Cur_index < Max) // ���簪�� ���� �ȿ� ���� ��, ǳ���� ��Ƴ����� ����.
            continue;
        Min = Cur_index < Min ? Cur_index : Min;
        Max = Cur_index > Max ? Cur_index : Max;
        answer++; //��Ƴ��Ҵ�.
    }

    answer += 2; // �ּ� 1, 2 ������ ǳ������ default�� �־��ش�.
    return answer;
}