#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[5];
	for (int i=0; i<5; i++) {
		cin >> a[i];
	}
	sort(a, a+5);
	int sum;
	cout << a[0]+a[4];
	return 0;
}
