#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer(n);
    
    if (s < n)
        return { -1 };
    else {
        int div = s / n;
        int lest = s % n;
        for (int i = 0; i < n; i++) {
            answer[i] = div;
        }
        for (int i = n - 1; i > -1 && lest > 0; i--) {
            answer[i]++;
            lest--;
        }
    }

    return answer;
}

int main() {
    vector<int> ans = solution(3, 8);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}