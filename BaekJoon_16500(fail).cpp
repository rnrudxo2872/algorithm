#include <bits/stdc++.h>
#define maxOflist 101

using namespace std;

string S;
string copyS;
int sizeOfDic;
string List[maxOflist];
bool Visit[maxOflist] = { 0, };
vector<string> pertum;

bool fin = false;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

void check(string str) {
	int Len = str.length();

	for (int i = 0; i < S.length(); i++) {
		string tem = S.substr(i, Len);
		
		//# 여러번에 걸쳐서 쓸수 있도록 해야한다.  
		//비교문자(사전 단어 목록)와 같다면 삭제
		if (tem.compare(str) == 0) {
			S.erase(i, Len);
		}
	}
}

void dfs(int depth) {
	if (depth >= sizeOfDic) {
		for (int i = 0; i < pertum.size(); i++) {
			check(pertum[i]);
		}
		if (S.length() != 0)
			S = copyS;
		else {
			cout << 1;
			exit(0);
		}
	}


	for (int i = 0; i < sizeOfDic; i++) {
		if (Visit[i])
			continue;

		Visit[i] = true;
		pertum.push_back(List[i]);
		dfs(depth + 1);
		pertum.pop_back();
		Visit[i] = false;
	}
}

int main() {
	init();

	cin >> S >> sizeOfDic;
	copyS = S;

	for (int i = 0; i < sizeOfDic; i++)
		cin >> List[i];

	dfs(0);

	cout << 0;
}