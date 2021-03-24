#include <iostream>
#include <map>
#define Max_Len 40
#define endl "\n"

using namespace std;

char stream[Max_Len];
int total = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cout << fixed;
	cout.precision(4);

	map<string, int> type_list;

	while (cin.getline(stream, Max_Len)) { // eof ¿œ ∂ß break
		type_list[stream] += 1;
		total++;
	}

	for (auto a : type_list)
		cout << a.first << " " << a.second * 100 / (double)total << endl;
}