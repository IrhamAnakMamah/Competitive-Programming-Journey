#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long long n;
	cin >> n;
	int a = 0;
	
	while (n != 0)
	{
		if ((n % 10 == 4) || (n % 10 == 7)){
			a++;
		}
		n = n /10;
	}
	
	if ((a == 4) || (a == 7)){
		cout << "YES" << endl;
	}else
		cout << "NO" << endl;
	
}