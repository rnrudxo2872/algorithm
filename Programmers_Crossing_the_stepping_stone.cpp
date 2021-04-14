#include <string>
#include <vector>

using namespace std;

vector<int> Stone;
int K;

bool solve(int mid) {
    int cnt = 0;
    for (int i = 0; i < Stone.size(); i++) {
        if (Stone[i] - mid <= 0)
            cnt++;
        else
            cnt = 0;
        if (cnt >= K)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int left = 0, right = 200000001;
    Stone = stones;
    K = k;

    while (left < right) {
        int mid = (left + right) / 2;

        //건널 수 있다면, 인원 추가
        if (solve(mid)) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return right;
}