#include <bits/stdc++.h>
using namespace std;

long long sum(long long a, long long n){
  if(a>n) return 0;
  else return ((n/a)*(a+(n/a)*a))/2;
}

int main (){
  int n;
  cin >> n;
  while (n--)
  {
    long long a;
    cin >> a;
    cout << sum(4,a) + sum(7,a) - sum(28,a) << '\n';
  }
  
}