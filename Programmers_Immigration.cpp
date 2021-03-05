#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 1000000000000001; //�ִ�
    sort(times.begin(), times.end()); // ��������

    ll left = 0;
    ll right = times[times.size() - 1] * n; // �ִ�ð����θ� ���� ��,
    ll mid = 0;

    while (left < right) {
        mid = (left + right) / 2;
        ll cnt = 0;

        for (int i = 0; i < times.size(); i++)
            cnt += mid / times[i];

        if (cnt >= n)
            right = mid - 1;
        else
            left = mid + 1;
    }
    answer = right + 1;

    return answer;
}