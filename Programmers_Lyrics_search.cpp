#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie {
public:
    Trie() : Node(), cnt(0) {};
    
    void insert(string str) {
        Trie* cur = this; //현재 Trie 지정

        for (char ch : str) {
            int idx = ch - 'a';
            cur->cnt++;

            if (cur->Node[idx] == nullptr)
                cur->Node[idx] = new Trie;
            cur = cur->Node[idx];
        }
        cur->cnt++; // 마지막 leaf
    }

    int Search(string str) {
        Trie* cur = this;

        for (char ch : str) {
            int idx = ch - 'a';

            if (ch == '?')
                return cur->cnt;
            cur = cur->Node[idx];

            if (cur == nullptr)
                return 0;
        }
        return cur->cnt;
    }

private:
    Trie* Node[26];
    int cnt;
};

Trie Root[10000];
Trie Rever_Root[10000];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (string str : words) {
        int len = str.length();

        Root[len - 1].insert(str);

        reverse(str.begin(), str.end());
        Rever_Root[len - 1].insert(str);
    }

    for (string str : queries) {
        int len = str.length();
        int Ans = 0;

        if (str[0] != '?')
            Ans = Root[len - 1].Search(str);
        else {
            reverse(str.begin(), str.end());
            Ans = Rever_Root[len - 1].Search(str);
        }

        answer.push_back(Ans);
    }

    return answer;
}