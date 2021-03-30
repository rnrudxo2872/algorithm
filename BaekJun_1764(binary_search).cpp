#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // ��������, ��������
vector<string> v; // �̺�Ž������ �Ű������� �Ѱ��ָ� �ð� �ʰ��� ���������� ����
vector<string> ans;

bool Binary_search(string str) { 
	int start = 0, mid = 0, end = v.size();

	while (start < end) {
		mid = (start + end) / 2;
		if (v[mid] == str)
			return true;
		if (v[mid] > str)
			end = mid;
		else
			start = mid + 1;
	}
	return false;
}

int main() {

	scanf_s("%d %d", &N, &M);
	v.resize(N); // ũ�� �Ҵ�

	for (int i = 0; i < N; i++) {
		cin >> v[i]; // push ���� ������ �ϱ����� �迭�� �ٷ� ����.
	}
	
	sort(v.begin(), v.end());
	string temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (Binary_search(temp))
			ans.push_back(temp);
	}

	sort(ans.begin(), ans.end());
	int Size = ans.size();
	printf("%d\n", Size);
	for (int i = 0; i < Size; i++) {
		printf("%s\n", ans[i].c_str());
	}
}