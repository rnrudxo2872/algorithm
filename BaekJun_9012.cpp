#include <iostream>
#include <vector>

using namespace std;

int N;
vector<char> stack;
vector<string> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		bool pos = true;
		cin >> temp;
		stack.clear();

		for (int j = 0; j < temp.length(); j++) {

			if (temp[j] == '(') {
				stack.push_back(temp[j]);
				continue;
			}
			if (stack.empty() && temp[j] == ')')
			{
				pos = false;
				break;
			}
			else
				stack.pop_back();
		}
		if (stack.size() > 0 || !pos)
			arr.push_back("NO");
		else
			arr.push_back("YES");
	}

	for (string ans : arr)
		cout << ans << '\n';
}