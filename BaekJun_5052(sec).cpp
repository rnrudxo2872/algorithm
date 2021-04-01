#include <iostream>
#define Max_Len 12
#define Max_Arr 10001
#define Max_Node Max_Len*Max_Arr

using namespace std;

typedef struct TRIE {
	bool fin;
	TRIE* Node[10];

	TRIE() {
		for (int i = 0; i < 10; i++)
			Node[i] = nullptr;
		fin = false;
	}
	~TRIE() {
		for (int i = 0; i < 10; i++)
			delete Node[i];
	}

	void insert(char* str);
	bool find(char* str);
};

TRIE* Root;
char Phone[Max_Arr][Max_Len];
int T, N;

void TRIE::insert(char* str) {
	if (*str == '\0') {
		fin = true;
		return;
	}

	int Cur = *str - '0';
	if (Node[Cur] == nullptr)
		Node[Cur] = new TRIE;
	Node[Cur]->insert(str + 1);
}

bool TRIE::find(char* str) {
	if (*str == '\0')
		return true;
	if (fin)
		return false;

	int Cur = *str - '0';
	return Node[Cur]->find(str + 1);
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		Root = new TRIE;

		for (int j = 0; j < N; j++)
			cin >> Phone[j];
		for (int j = 0; j < N; j++)
			Root->insert(Phone[j]);

		bool possible = true;
		for (int j = 0; j < N; j++) {
			if (!Root->find(Phone[j])) {
				possible = false;
				break;
			}
		}
		if (possible)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}