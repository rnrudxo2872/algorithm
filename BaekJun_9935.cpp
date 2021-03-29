#include <iostream>
#include <vector>

using namespace std;


void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();

	string Boom, str;
	cin >> str >> Boom;

	vector<char> stack;
	for (int i = 0; i < str.length(); i++) {
		stack.push_back(str[i]);
		if (stack.size() < Boom.length())
			continue;
		int lastOfs = stack.size() - 1;
		int lastOfb = Boom.length() - 1;
		if (stack[lastOfs] == Boom[lastOfb]) { // stack길이가 폭발보다 길거나 같고,폭발 문자열의 마지막 글자가 같으면,
			bool possible = true;
			for (int j = 1; j <= lastOfb; j++) { // 탐색
				if (stack[lastOfs - j] != Boom[lastOfb - j]) {
					possible = false;
					break;
				}
			}
			if (possible) // 폭발
				stack.erase(stack.end() - lastOfb - 1, stack.end());
		}
	}

	if (stack.size() == 0) {
		printf("FRULA");
		return 0;
	}
	for (int i = 0; i < stack.size(); i++)
		printf("%c", stack[i]);
}