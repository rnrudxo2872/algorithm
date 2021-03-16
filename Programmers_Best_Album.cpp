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

    for (int i = 0; i < genres.size(); i++) { // �ʿ� �־� ��� ����
        string Genres = genres[i];
        int Play = plays[i];
        album[Genres] += Play;
    }
    for (pair<string, int> item : album)
        Greater.push_back({ item.second, item.first });

    int sizeOfPlay = plays.size();
    sort(Greater.begin(), Greater.end(), cmp); // ��������


    for (int i = 0; i < album.size(); i++) {
        string Cur = Greater[i].second; // ���� album item
        int inner[2] = { -1,-1 }; // -1�� ���ٴ� ��.

        for (int j = 0; j < sizeOfPlay; j++) {
            if (Cur.compare(genres[j]) == 0) { // ���� searching���� ���ٸ�,
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
                if (plays[inner[1]] > plays[inner[0]]) { // inner���� ���� ����.
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