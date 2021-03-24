#include<iostream>
#define Max_Len 150
#define Max_Type 10000

using namespace std;

struct TRIE {
	bool fin = false;
	TRIE* Node[Max_Len];
	int cnt = 0;

	void insert(char* str);
	void find(int depth);
};

TRIE* Root, Nodepool[Max_Type];
int N_idx = 0;
int total = 0;
int idx = 0;
char temp[Max_Len];

TRIE* setNode() {
	TRIE* New = &Nodepool[N_idx++];
	New->fin = false;

	for (int i = 0; i < Max_Len; i++)
		New->Node[i] = NULL;
	return New;
}

void TRIE::insert(char* str) {
	if (*str == NULL) {
		fin = true;
		total += 1;
		cnt += 1; //cnt로 같은 단어가 몇개 있는지.
		//cout << cnt << " : " << total << endl;
		return;
	}
	int Cur = *str;
	if (Node[Cur] == NULL)
		Node[Cur] = setNode();
	Node[Cur]->insert(str + 1);
}

void TRIE::find(int depth) {
	if (cnt > 0) { // cnt가 0보다 크다면 한 type이 완성이 된 것. 출력
		//cout << cnt << "(((()))))" << total << endl;
		temp[depth] = NULL;
		cout << temp << " " << 100 * cnt / (double)total << "\n";
	}

	for (int i = 0; i < Max_Len; i++) {
		if (Node[i]) {
			temp[depth] = i;
			Node[i]->find(depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cout << fixed; // 소수점 고정
	cout.precision(4); // 4째 자리까지

	Root = setNode();
	while (cin.getline(temp, 35)) {
		Root->insert(temp);
		idx++;
	}
	Root->find(0);
}
/*
터미널에서 eof 방법
윈도우 : ctrl + Z
https://www.acmicpc.net/board/view/24867
*/