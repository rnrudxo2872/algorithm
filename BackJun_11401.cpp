#include<iostream>

using namespace std;

long long int P = 1000000007;

long long int perma(long long int x, long long int y) {
	long long int ans = 1;
	
	while (y > 0) {
		if (y % 2) {
			ans *= x;
			ans = ans % P;
		}
		x *= x;
		x = x % P;
		y /= 2;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int N = 0, K = 0;

	cin >> N >> K;

	long long int n1 = 1, n2 = 1, n3 = 1;


	for (long long int i = N; i > 0; i--) {
		n1 *= i;
		n1 = n1 % P;
	}

	for (long long int i = K; i > 0; i--) {
		n2 *= i;
		n2 = n2 % P;
	}

	for (long long int i = N - K; i > 0; i--) {
		n3 *= i;
		n3 = n3 % P;
	}
	long long int B = n2  % P;
	B *= n3;
	B %= P;
	long long int result = perma(B,P-2);
	result = ((result%P) * (n1%P)) % P;
	cout << result;
}