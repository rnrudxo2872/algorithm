#include <iostream>
#include <string>

#define Max_length 11
#define Max_Num 10010

using namespace std;

struct TRIE{ // TRIE
	bool fin = false;
	TRIE *Node[Max_length]; // ��ȭ��ȣ �ִ� ����(= ����� �ִ������ �迭 node�� ������.)

	void insert(char* str); // ���� ���ڸ� �߰��Ѵ�.
	bool check(char* str); // �ϰ��� �˻� function.
};

TRIE *Root, Nodepool[Max_length*Max_Num];
int N_index = 0;
int T;
char Numbering[Max_Num][Max_length]; // ��ȭ ��ȣ��
int n;

TRIE *setNode() { // ���ο� ��带 �����Ѵ�.
	TRIE *NEW = &Nodepool[N_index++]; // �� Nodepool�� �ּҰ��� ����Ų��. ��, root ����(branch)�� ����� ��
	NEW->fin = false;
	for (int i = 0; i < Max_length; i++)
		NEW->Node[i] = NULL;
	return NEW; // ���� ������ Node ��ȯ.
}


void TRIE::insert(char* str) { // ���� ���ڸ� �߰��Ѵ�.
	
		if (*str == NULL) { // ���� ���� ���ڰ� ����ִٸ�
			fin = true; // �� ���ڿ��� ���̴�.
			return;
		}

		int Cur = *str - '0'; // ���� ���� ������ ������ �ε����� ���� �޴´�.
		if (Node[Cur] == NULL) Node[Cur] = setNode(); // ���� ���� ���ڰ� ���ٸ�, ���ο� ��带
															// ����� ������ �����.

		Node[Cur]->insert(str + 1); // ���� �ּҰ��� ���ڿ��� ���� ���ڸ� insert�Ѵ�. ex)3���� -> 2���ڷ�.
}

bool TRIE::check(char* str) {

	if (*str == NULL)
		return true;
	if (fin == true) // str�� NULL�� �ƴѵ� node�� ����� ���ڿ��� ������ ���� ������ ��, �������� �ϰ����� ���� ��.
		return false;
	int Cur = *str - '0';
	return Node[Cur]->check(str + 1); // ���� ���� �˻�
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> T;
	for (int i = 0; i < T; i++) {
		N_index = 0;
		Root = setNode(); // case���� �ʱ�ȭ
		cin >> n;

		for (int j = 0; j < n; j++) // ��ȭ ��ȣ �Է�
			cin >> Numbering[j];

		for (int j = 0; j < n; j++)
			Root->insert(Numbering[j]); // ��ȭ��ȣ�θ� �ִ´�.
		bool flag = true;

		for (int j = 0; j < n; j++) {
			if (flag == true)
				flag = Root->check(Numbering[j]);
			if (flag == false)
				break;
		}
		string answer = "";
		if (flag)
			answer = "YES";
		else
			answer = "NO";
		
		cout << answer << endl;
	}
}