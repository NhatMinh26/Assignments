#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n, min, ucln;
	cin >> m >> n;
	if (m>n) {
		min = n;
	} else {
		min = m;
	}
	for (int i = 1; i <= min; i++)
	{
		if (m%i == 0 && n%i == 0)
		{
			ucln = i;
		}
	}
	cout << ucln;
	return 0;
}
