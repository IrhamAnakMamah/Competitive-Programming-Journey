#include <bits/stdc++.h>
using namespace std;

bool op (const string &a, const string &b){
  return a.length() < b.length();
}

int main(){
  int n;
  cin >> n;

  string a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a,a+n, op);
  for (int i = 0; i < n; i++)
  {
    cout << a[i];
  }
  cout << endl;
}