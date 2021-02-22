#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    if (N == number) // N 하나로 만들 수 있는 수는 N 뿐.
        return 1;
    
    vector<unordered_set<int>> v(8);
    v[0].insert(N);

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                //cout << i << " "  << j << " " << k << endl;
                if (j + k + 1 != i)
                    continue;
                for (int a : v[j]) {
                    for (int b : v[k]) {
                        v[i].insert(a + b);
                        v[i].insert(a * b);
                        if (a / b > 0)
                            v[i].insert(a / b);
                        if (a - b > 0)
                            v[i].insert(a - b);
                        //cout << "a : "<< a<< ", b : " << b << endl;
                    }
                }
                //cout << "after" << endl;
            }
        }
        string dum = "";
        for (int x = 0; x <= i; x++) {
            dum += to_string(N);
        }
        v[i].insert(stoi(dum));

        if (v[i].count(number)) {
            return i + 1;
        }
            
    }
    answer = -1;
    return answer;
}

int main() {
    cout << solution(5, 31168);
}