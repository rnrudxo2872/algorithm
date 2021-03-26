#include <iostream>
#define Max_Word 52
#define Alpha 26

using namespace std;

bool alpha[Alpha];
string TWord[Max_Word];
int N, K;
int MaxCnt = 0;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	char pre[5] = { 'a','n','t','i','c' };
	for (int i = 0; i < 5; i++) { // 기본 글자 세팅
		int idx = pre[i] - 'a';
		alpha[idx] = true;
	}
}

int search() {
	int Cnt = 0;
	for (int i = 0; i < N; i++) {
		bool possible = true;
		for (int j = 0; j < TWord[i].length(); j++) {
			int Cur = TWord[i][j] - 'a';
			if (!alpha[Cur]) { // 아는 글자 목록에 글자가 없다면, 못 읽는다.
				possible = false;
				break;
			}
		}
		if (possible) // 읽을 수 있다면 카운트.
			Cnt++;
	}
	return Cnt;
}

void dfs(int depth, int idx) {

	if (depth == K) { // 배울 수 있는 글자 개수를 채웠을 때,
		int temp = search();
		MaxCnt = MaxCnt > temp ? MaxCnt : temp; // 모은 글자들로 읽을 수 있는 단어 수를 구한다.
		return;
	}

	for (int i = idx; i < Alpha; i++) { // 알파벳을 전부 탐색한다.
		if (!alpha[i]) {
			alpha[i] = true;
			dfs(depth + 1, i);
			alpha[i] = false;
		}
	}
}

int main() {

	scanf("%d %d", &N, &K); // 단어 수, 글자 수
	if (K < 5) { // 기본 단어길이 미만.
		printf("0\n");
		return 0;
	}

	fill(alpha, alpha + Alpha, 0);
	init();
	int cnt = 5;

	for (int i = 0; i < N; i++) { // 단어들 입력
		cin >> TWord[i];
	}
	K -= 5; // 이미 a n t i c 를 기본적으로 알기에 빼준다.
	dfs(0, 0);

	printf("%d\n", MaxCnt);
}