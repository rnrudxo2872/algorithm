#include <iostream>
#include <string>
#include <vector>
#define Max_Len 30

using namespace std;

typedef struct TRIE {
    bool fin;
    int child;
    TRIE* Node[Max_Len];

    TRIE() { // 트라이가 생성될 시,
        this->fin = false;
        this->child = 0;
        fill(Node, Node + Max_Len, nullptr);  // 초기화 작업
    }

    ~TRIE() {
        for (int i = 0; i < Max_Len; i++)
            delete Node[i]; // 메모리 제거
    }

    void insert(const char* str, int depth);
    void find(const char* str, int cnt);
}TRIE;

TRIE* Root;
int N_idx = 0; // 전체 node index
int Ans_cnt = 0;

void TRIE::insert(const char* str, int depth) {
    child++;
    if (*str == '\0') { // 문자가 null 이라면,
        fin = true;
        return;
    }

    int Cur = *str - 'a';
    if (Node[Cur] == nullptr) {
        Node[Cur] = new TRIE;
    }
    Node[Cur]->insert(str + 1, depth + 1);
}

void TRIE::find(const char* str, int cnt) {
    if (child == 1 || *str == '\0') { // child가 1이 아니지만 문장이 끝이라면 자신보다 긴 문자열이 있다는 것, 즉 구분짓기 위해 다 쳐야 함.
        Ans_cnt += cnt;
        return;
    }

    int Cur = *str - 'a';
    Node[Cur]->find(str + 1, cnt + 1);
}

int solution(vector<string> words) {
    int answer = 0;

    Root = new TRIE;
    for (int i = 0; i < words.size(); i++) {
        Root->insert(words[i].c_str(), 1);
    }

    for (int i = 0; i < words.size(); i++) {
        Root->find(words[i].c_str(), 0); //카운트 값 계산
    }
    answer = Ans_cnt;

    return answer;
}