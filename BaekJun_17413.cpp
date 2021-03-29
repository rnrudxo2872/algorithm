#include <iostream>
#include <vector>
#define Max_Len 100001

using namespace std;

char str[Max_Len];
vector<char> stack;

void init() {
	ios::sync_with_stdio(false);
	cout.tie(); cin.tie();
}

void print_stack() {
	while (!stack.empty()) {
		printf("%c", stack.back());
		stack.pop_back();
	}
}

int main() {
	init();

	cin.getline(str, Max_Len);
	bool tag = false;

	for (int i = 0; i < Max_Len; i++) {
		if (str[i] == NULL) {
			print_stack();
			break;
		}
		else if (str[i] == 32) {
			print_stack();
			printf(" ");
			continue;
		}
		if (str[i] == '>') {
			tag = false;
			printf("%c", str[i]);
			continue;
		}
		if (str[i] == '<') {
			print_stack();
			tag = true;
			printf("%c", str[i]);
			continue;
		}
		if (tag)
			printf("%c", str[i]);
		else
			stack.push_back(str[i]);
	}
}