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
		cnt += 1; //cnt�� ���� �ܾ � �ִ���.
		//cout << cnt << " : " << total << endl;
		return;
	}
	int Cur = *str;
	if (Node[Cur] == NULL)
		Node[Cur] = setNode();
	Node[Cur]->insert(str + 1);
}

void TRIE::find(int depth) {
	if (cnt > 0) { // cnt�� 0���� ũ�ٸ� �� type�� �ϼ��� �� ��. ���
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

	cout << fixed; // �Ҽ��� ����
	cout.precision(4); // 4° �ڸ�����

	Root = setNode();
	while (cin.getline(temp, 35)) {
		Root->insert(temp);
		idx++;
	}
	Root->find(0);
}
/*
�͹̳ο��� eof ���
������ : ctrl + Z
https://www.acmicpc.net/board/view/24867
*/