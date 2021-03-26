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
	for (int i = 0; i < 5; i++) { // �⺻ ���� ����
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
			if (!alpha[Cur]) { // �ƴ� ���� ��Ͽ� ���ڰ� ���ٸ�, �� �д´�.
				possible = false;
				break;
			}
		}
		if (possible) // ���� �� �ִٸ� ī��Ʈ.
			Cnt++;
	}
	return Cnt;
}

void dfs(int depth, int idx) {

	if (depth == K) { // ��� �� �ִ� ���� ������ ä���� ��,
		int temp = search();
		MaxCnt = MaxCnt > temp ? MaxCnt : temp; // ���� ���ڵ�� ���� �� �ִ� �ܾ� ���� ���Ѵ�.
		return;
	}

	for (int i = idx; i < Alpha; i++) { // ���ĺ��� ���� Ž���Ѵ�.
		if (!alpha[i]) {
			alpha[i] = true;
			dfs(depth + 1, i);
			alpha[i] = false;
		}
	}
}

int main() {

	scanf("%d %d", &N, &K); // �ܾ� ��, ���� ��
	if (K < 5) { // �⺻ �ܾ���� �̸�.
		printf("0\n");
		return 0;
	}

	fill(alpha, alpha + Alpha, 0);
	init();
	int cnt = 5;

	for (int i = 0; i < N; i++) { // �ܾ�� �Է�
		cin >> TWord[i];
	}
	K -= 5; // �̹� a n t i c �� �⺻������ �˱⿡ ���ش�.
	dfs(0, 0);

	printf("%d\n", MaxCnt);
}