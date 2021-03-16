#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first > b.first)
        return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> album;
    vector<pair<int, string>> Greater;

    for (int i = 0; i < genres.size(); i++) { // 맵에 넣어 목록 만듦
        string Genres = genres[i];
        int Play = plays[i];
        album[Genres] += Play;
    }
    for (pair<string, int> item : album)
        Greater.push_back({ item.second, item.first });

    int sizeOfPlay = plays.size();
    sort(Greater.begin(), Greater.end(), cmp); // 내림차순


    for (int i = 0; i < album.size(); i++) {
        string Cur = Greater[i].second; // 현재 album item
        int inner[2] = { -1,-1 }; // -1은 없다는 것.

        for (int j = 0; j < sizeOfPlay; j++) {
            if (Cur.compare(genres[j]) == 0) { // 현재 searching값과 같다면,
                if (inner[0] == -1) {
                    inner[0] = j;
                }
                else if (inner[1] == -1) {
                    inner[1] = j;
                }
                else if (plays[inner[0]] < plays[j]) {
                    int temp = inner[0]; //swap
                    inner[0] = j;
                    inner[1] = temp;
                }
                else if (plays[inner[1]] < plays[j]) {
                    inner[1] = j;
                }
                if (plays[inner[1]] > plays[inner[0]]) { // inner들을 정렬 해줌.
                    int temp = inner[0]; //swap
                    inner[0] = inner[1];
                    inner[1] = temp;
                }
            }
        }

        if (plays[inner[1]] == plays[inner[0]]) {
            if (inner[1] < inner[0]) {
                int temp = inner[0]; //swap
                inner[0] = inner[1];
                inner[1] = temp;
            }
        }

        if (inner[0] != -1)
            answer.push_back(inner[0]);
        if (inner[1] != -1)
            answer.push_back(inner[1]);
    }

    return answer;
}