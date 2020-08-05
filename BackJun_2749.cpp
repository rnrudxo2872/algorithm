#include<iostream>

using namespace std;

typedef long long int LL;

int main() {
	LL N = 0;
	cin >> N;
	LL tem_0 = 0, tem_1 = 1, tem_2 = 1;
	if (N == 0) {
		cout << tem_0;
	}
	else if(N == 1) {
		cout << tem_1;
	}
	else if (N == 2) {
		cout << tem_2;
	}
	else {
		N %= 1500000;
		for (int i = 2; i < N; i++) {
			tem_0 = tem_1 + tem_2;
			
			
			tem_0 %= 1000000;

			tem_2 = tem_1;
			tem_2 %= 1000000;

			tem_1 = tem_0;
			tem_1 %= 1000000;
		}
		cout << tem_0;
	}
}