#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,l,r;
  cin >> n >> l >> r;

  string s;
  cin >> s;

  int sum = 0;
  for (int i = l-1; i < r; i++)
  {
    if(s[i] == 'o'){
      sum++;
    }
  }
  
  cout << (sum == (r-l+1) ? "Yes" : "No") << endl;
}