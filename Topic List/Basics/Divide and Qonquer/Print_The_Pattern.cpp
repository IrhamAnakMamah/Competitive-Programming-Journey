#include <bits/stdc++.h>
using namespace std;

string ans[15];

void f(){
  ans[0] = "A";
  for (int i = 1; i < 15; i++)
  {
    char c = 'A' + i;
    string x;
    x = c; 
    string temp = ans[i-1] + x + ans[i-1];
    ans[i] = temp;
  }
}

int main(){
  f();
  int n;
  cin >> n;
  cout << ans[n-1];
}