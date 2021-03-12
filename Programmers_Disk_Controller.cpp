#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Job {
    int doing;
    int idx; // 요청받은 시간
};

struct cmp {
    bool operator()(Job& a, Job& b) {
        if (a.doing != b.doing)
            return a.doing > b.doing;
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());

    int index = 0;
    priority_queue<Job, vector<Job>, cmp> pq;
    int time = 0; // 걸린 시간

    while (!pq.empty() || index < jobs.size()) {

        if (index < jobs.size() && time >= jobs[index][0]) {
            pq.push({ jobs[index][1],jobs[index][0] });
            //cout << index << endl;
            index++;
            continue;
        }
        if (!pq.empty()) {
            int did = pq.top().doing;
            int do_start = pq.top().idx;

            time += did;
            answer += time - do_start;
            pq.pop();
        }
        else
            time = jobs[index][0];

    }
    answer /= jobs.size();

    return answer;
}