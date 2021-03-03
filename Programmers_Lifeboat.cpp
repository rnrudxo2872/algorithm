#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int sum = 0;
    int end = people.size() - 1;
    int i = 0;
    while (i <= end) {

        sum += people[i];

        if (sum + people[end] <= limit)
            ++i;
        --end;

        sum = 0;
        ++answer;
    }

    return answer;
}