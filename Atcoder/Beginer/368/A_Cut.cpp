#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int i = (n-k);
  do
  {
    cout << a[i] << " ";
    i = (i+1) % n;
  } while (i != n-k);
  cout << endl;
  
  
}