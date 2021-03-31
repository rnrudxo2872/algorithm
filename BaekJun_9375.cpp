#include <iostream>
#include <unordered_map>

using namespace std;

int T, N;
unordered_map <string, int> List;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> T;
	for (int i = 0; i < T; i++) {
		List.clear();
		cin >> N;
		string temp1, temp2;
		for (int i = 0; i < N; i++) {
			cin >> temp1 >> temp2;
			List[temp2] += 1; // �� ������ �� �̸����� �־�д�.
		}
		int ans = 1;

		for (auto element : List) {
			ans *= (element.second + 1);
		}
		ans -= 1; // ��� ���� ���Դ� ���� ����
		cout << ans << '\n';
	}
}