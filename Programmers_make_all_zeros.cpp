#include <bits/stdc++.h>

using namespace std;

void dfs(long long now, long long pre, vector<long long> &a, vector<long long> edges[], long long &answer) {
    
    for(long long i = 0; i < edges[now].size(); ++i) {
        if(pre == edges[now][i]) continue;
        
        dfs(edges[now][i], now, a, edges, answer);
    }
    
    answer += abs(a[now]);
    
    if(pre == -1) return;
    a[pre] += a[now];
}

void setEdges(vector<long long> edges[], vector<vector<int>> info) {
    for(long long i = 0; i < info.size(); ++i) {
        long long x1 = info[i][0];
        long long x2 = info[i][1];
        
        edges[x1].push_back(x2);
        edges[x2].push_back(x1);
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    
    vector<long long> b(a.begin(), a.end());
    if(accumulate(b.begin(), b.end(), 0ll) != 0) return -1;
    
    vector<long long> t_edges[300000];
    setEdges(t_edges, edges);
    
    dfs(0, -1, b, t_edges, answer);
    
    return answer;
}