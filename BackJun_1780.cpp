#include<iostream>
#include<cstring>

using namespace std;

int map[2200][2200];

int one = 0, zero = 0, minu = 0;

void div_nine(int xs,int ys, int size) {
	int check_p = map[ys][xs];

	for (int y = ys; y < size+ys; y++) {
		for (int x = xs; x < size+xs; x++) {
			if (map[y][x] != check_p) {
				int div_size = size / 3;
				div_nine(xs, ys, div_size);
				div_nine(xs + (size / 3), ys, (size / 3));
				div_nine(xs + ((size * 2) / 3), ys, (size / 3)); //1 row

				div_nine(xs, ys + (size / 3), (size / 3));
				div_nine(xs + (size / 3), ys + (size / 3), (size / 3));
				div_nine(xs + ((size * 2) / 3), ys + (size / 3), (size / 3)); //sec row

				div_nine(xs, ys + (size * 2 / 3), (size / 3));
				div_nine(xs + (size / 3), ys + (size * 2 / 3), (size / 3));
				div_nine(xs + ((size * 2) / 3), ys + (size * 2 / 3), (size / 3)); //thr row

				return;
			}
		}
	}

	if (check_p == -1) {
		minu++;
	}
	else if (check_p == 0) {
		zero++;
	}
	else if (check_p == 1) {
		one++;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int size = 0;
	memset(map, 0, sizeof(map));
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> map[i][j];
		}
	}

	div_nine(0, 0, size);

	cout << minu << "\n";
	cout << zero << "\n";
	cout << one << "\n";
}