#include<iostream>
#include<cmath>

using namespace std;

long long int A=0, B=0, C=0;

long long int powk(long long int a, long long int b,long long int c) {
	if (b == 0) {
		return 1;
	}
	long long int ans = powk(a, b / 2, c);
	if ((b % 2) == 0) {
		return (ans * ans)%c;
	}
	else {
		return (((ans * ans)%c) * a)%c;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A;
	cin >> B;
	cin >> C;

	cout << powk(A,B,C);

	return 0;
}