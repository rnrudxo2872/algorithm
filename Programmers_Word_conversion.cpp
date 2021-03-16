#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;
struct Node {
    int cnt;
    string str;
};

void bfs(string start, string target, vector<string> words) {
    queue<Node> qu;
    qu.push({ 0,start });
    int Length = start.length();

    while (!qu.empty()) {
        string Cur = qu.front().str;
        int Cnt = qu.front().cnt;
        if (Cur.compare(target) == 0) {
            answer = Cnt;
            return;
        }
        qu.pop();

        for (int i = 0; i < words.size(); i++) {
            int wrong = 0;
            string Next = words[i];
            for (int j = 0; j < Length; j++) {
                if (Cur[j] != Next[j])
                    wrong++;
            }
            if (wrong == 1)
                qu.push({ Cnt + 1,Next });
        }
    }
}


int solution(string begin, string target, vector<string> words) {

    bool inner = false;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].compare(target) == 0)
            inner = true; // 타겟 단어가 존재할 시,
    }
    if (!inner)
        return 0;

    bfs(begin, target, words);

    return answer;
}