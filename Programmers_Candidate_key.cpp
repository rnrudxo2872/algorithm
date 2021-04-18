#include <bits/stdc++.h>

using namespace std;

// ** 후보키 **
// 후보 키 ( 데이터 식별할 수 있는)의 개수를 찾는문제

bool Check(int row, int col, vector<vector<string>> relation, int On) {
    for (int i = 0; i < row - 1; i++) {
        for (int j = i + 1; j < row; j++) {
            
            //모든 col의 값이 같은가
            bool Same = true;

            for (int k = 0; k < col; k++) {
                if (!(On & 1 << k))
                    continue;
                if (relation[i][k].compare(relation[j][k]) != 0) {
                    Same = false;
                    break;
                }
            }
            if (Same)
                return false;
        }
    }
    return true;
}

int bitsCount(int a) {
    int ret = 0;
    while (a) {
        if (a & 1)
            ret++;
        a = a >> 1;
    }
    return ret;
}

bool cmp(int &a, int &b) {
    int x = bitsCount(a), y = bitsCount(b);
    return x > y;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int row = relation.size();
    int col = relation[0].size();
    vector<int> Candidate;

    for (int i = 1; i < 1 << col; i++) {
        if (Check(row, col, relation, i))
            Candidate.push_back(i);
    }

    sort(Candidate.begin(), Candidate.end(), cmp);

    while (!Candidate.empty()) {
        int Cur = Candidate.back();
        Candidate.pop_back();
        answer++;

        vector<int>::iterator it;
        for (it = Candidate.begin(); it != Candidate.end();) {
            if ((Cur & *it) == Cur)
                it = Candidate.erase(it);
            else
                it++;
        }
    }

    return answer;
}
