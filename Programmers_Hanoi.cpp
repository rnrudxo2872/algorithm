#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void recorde(vector<vector<int>> &v, int from, int to) {
    v.push_back({ from,to });
}

void dfs(vector<vector<int>> &v, int from, int to, int temp, int n) {
    if (n == 1) {
        recorde(v, from, to);
        return;
    }
    dfs(v, from, temp, to, n - 1);
    recorde(v, from, to);
    dfs(v, temp, to, from, n - 1);
}

vector<vector<int>> solution(int n) {

    dfs(answer,1,3,2,n);

    return answer;
}

int main() {
    
}