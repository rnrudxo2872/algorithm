#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visit[500001] = { 0, };

int solution(std::vector<int> a) {
    int answer = 0;
    if (a.size() <= 1)
        return 0;
    for (int i = 0; i < a.size(); i++) { // ���� ���� �ľ�
        visit[a[i]] += 1;
    }

    for (int i = 0; i <= a.size(); i++) {
        if (!visit[i]) // ���ڰ� �������� �ʴ´ٸ� �ѱ��.
            continue;
        if (visit[i] <= answer) // �ð��ʰ��� �߰��� ���ǹ�, ���� �ִ밪���� ���� ������ ��Ÿ������ �Ⱥ��� �ȴ�.
            continue;
        int cnt = 0;
        for (int j = 0; j < a.size() - 1; j++) { //�� ���ڰ� ���Ե� ��Ÿ������ ���̸� ã�´�.
            if ((a[j] != a[j + 1]) && (a[j] == i || a[j+1] == i)) {
                cnt++;
                j++; // ��Ÿ�����̸�!! �Ѱ��� ¦���� index�� 2ĭ�� �̵��ؾ��Ѵ�.
            }
        }
        answer = answer > cnt ? answer : cnt;
    }
    answer *= 2;
    return answer;
}

int main() {
    cout << solution({ 4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3 }) << endl;
}