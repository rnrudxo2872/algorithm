#include <iostream>
#include <string>
#include <vector>
#define Max_Len 30

using namespace std;

typedef struct TRIE {
    bool fin;
    int child;
    TRIE* Node[Max_Len];

    TRIE() { // Ʈ���̰� ������ ��,
        this->fin = false;
        this->child = 0;
        fill(Node, Node + Max_Len, nullptr);  // �ʱ�ȭ �۾�
    }

    ~TRIE() {
        for (int i = 0; i < Max_Len; i++)
            delete Node[i]; // �޸� ����
    }

    void insert(const char* str, int depth);
    void find(const char* str, int cnt);
}TRIE;

TRIE* Root;
int N_idx = 0; // ��ü node index
int Ans_cnt = 0;

void TRIE::insert(const char* str, int depth) {
    child++;
    if (*str == '\0') { // ���ڰ� null �̶��,
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
    if (child == 1 || *str == '\0') { // child�� 1�� �ƴ����� ������ ���̶�� �ڽź��� �� ���ڿ��� �ִٴ� ��, �� �������� ���� �� �ľ� ��.
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
        Root->find(words[i].c_str(), 0); //ī��Ʈ �� ���
    }
    answer = Ans_cnt;

    return answer;
}