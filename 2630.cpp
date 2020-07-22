#include<iostream>
#include<cstring>

using namespace std;

int map[129][129];
int one = 0, zero = 0;

void div_paper(int xst, int yst, int xe, int ye) {

	int check = map[xst][yst];

	for (int x = xst; x < xe; x++) {
		for (int y = yst; y < ye; y++) {
			if (check == map[x][y]) {
			}
			else {
				div_paper(xst, yst, (xst + xe) / 2, (yst + ye) / 2);
				div_paper((xst + xe) / 2, yst, xe, (yst + ye) / 2);
				div_paper(xst, (yst + ye) / 2, (xst + xe) / 2, ye);
				div_paper((xst + xe) / 2, (yst + ye) / 2, xe, ye);

				return;
			}
		}
	}
	if (check == 0) {
		zero += 1;
	}
	else if (check == 1) {
		one += 1;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(map, 0, sizeof(map));

	int size = 0;
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> map[i][j];
		}
	}

	div_paper(0, 0, size, size);

	cout << zero << "\n";
	cout << one << "\n";

	return 0;
}