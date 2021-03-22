#include <iostream>
#include <string>

#define Max_length 11
#define Max_Num 10010

using namespace std;

struct TRIE{ // TRIE
	bool fin = false;
	TRIE *Node[Max_length]; // 전화번호 최대 길이(= 노드의 최대길이인 배열 node를 가진다.)

	void insert(char* str); // 다음 문자를 추가한다.
	bool check(char* str); // 일관성 검사 function.
};

TRIE *Root, Nodepool[Max_length*Max_Num];
int N_index = 0;
int T;
char Numbering[Max_Num][Max_length]; // 전화 번호부
int n;

TRIE *setNode() { // 새로운 노드를 형성한다.
	TRIE *NEW = &Nodepool[N_index++]; // 빈 Nodepool의 주소값을 가리킨다. 즉, root 갈래(branch)가 생기는 것
	NEW->fin = false;
	for (int i = 0; i < Max_length; i++)
		NEW->Node[i] = NULL;
	return NEW; // 새로 형성한 Node 반환.
}


void TRIE::insert(char* str) { // 다음 문자를 추가한다.
	
		if (*str == NULL) { // 만약 다음 문자가 비어있다면
			fin = true; // 이 문자열의 끝이다.
			return;
		}

		int Cur = *str - '0'; // 현재 들어온 문자의 정수로 인덱스의 값을 받는다.
		if (Node[Cur] == NULL) Node[Cur] = setNode(); // 만약 현재 문자가 없다면, 새로운 노드를
															// 만들어 갈래를 만든다.

		Node[Cur]->insert(str + 1); // 다음 주소값의 문자열로 가서 문자를 insert한다. ex)3글자 -> 2글자로.
}

bool TRIE::check(char* str) {

	if (*str == NULL)
		return true;
	if (fin == true) // str이 NULL이 아닌데 node에 저장된 문자열은 끝나지 않은 문자일 때, 문제에서 일관성이 없는 것.
		return false;
	int Cur = *str - '0';
	return Node[Cur]->check(str + 1); // 다음 문자 검색
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> T;
	for (int i = 0; i < T; i++) {
		N_index = 0;
		Root = setNode(); // case마다 초기화
		cin >> n;

		for (int j = 0; j < n; j++) // 전화 번호 입력
			cin >> Numbering[j];

		for (int j = 0; j < n; j++)
			Root->insert(Numbering[j]); // 전화번호부를 넣는다.
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