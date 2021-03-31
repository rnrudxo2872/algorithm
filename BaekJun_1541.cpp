#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Exp;
string arr[52];
bool visit[52];
int idx = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> Exp;

	string temp = "";
	for (int i = 0; i < Exp.length(); i++) {
		if (Exp[i] == '+' || Exp[i] == '-') {
			arr[idx] = temp;
			temp = "";
			idx++;
			arr[idx] = Exp[i];
			idx++;
			continue;
		}
		if (i == Exp.length()-1) {
			arr[idx] = temp + Exp[i];
			break;
		}
		temp += Exp[i];
	}
	int Cur = 0;
	bool minu = false;
	for (int i = 0; i < 52; i++) {
		if (arr[i].length() == 0) 
			break;
		if (arr[i] == "+" || arr[i] == "-") {
			if (arr[i] == "-")
				minu = true;
			else
				continue;
			continue;
		}
		if (minu)
			Cur -= stoi(arr[i]);
		else
			Cur += stoi(arr[i]);
	}
	cout << Cur << endl;
}