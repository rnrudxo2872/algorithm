#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 1000000000000001; //최대
    sort(times.begin(), times.end()); // 오름차순

    ll left = 0;
    ll right = times[times.size() - 1] * n; // 최대시간으로만 했을 때,
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