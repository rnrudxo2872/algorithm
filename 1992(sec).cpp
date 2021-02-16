#include<iostream>
#include<string>

using namespace std;

int video_map[64][64];

string result = "";

void div_query(int xst,int yst, int xend, int yend) {
	int check = video_map[xst][yst];
	result += "(";

	for (int x = 0; x < xend; x++) {
		for (int y = 0; y < yend; y++) {
			if (check == video_map[x][y]) {
				continue;
			}
			else {
				//div_query(xst, yst, (xst + xend) / 2, (yst + yend) / 2);
				//div_query((xst + xend) / 2, yst, xend, (yst + yend) / 2);
				//div_query(xst, (yst + yend) / 2, (xst + xend) / 2, yend);
				//div_query((xst + xend) / 2, (yst + yend) / 2, xend, yend);

				div_query(xst, yst, (xst + xend) / 2, (yst + yend) / 2);
				div_query(xst, (yst + yend) / 2, (xst + xend) / 2, yend);
				div_query((xst + xend) / 2, yst, xend, (yst + yend) / 2);
				div_query((xst + xend) / 2, (yst + yend) / 2, xst, yend);
				result += ")";
				return;
			}
		}
	}
	if (check == 1) {
		result += "1";
	}
	else if (check == 0) {
		result += "0";
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s = "";
	int size = 0;

	cin >> size;
	
	for (int i = 0; i < size; i++) {
		cin >> s;
		for (int j = 0; j < size; j++) {
			video_map[i][j]=s[i]-'0';
		}
	}

	div_query(0, 0, size, size);

	cout << result << "\n";

	return 0;
}