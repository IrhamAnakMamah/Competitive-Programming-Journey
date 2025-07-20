#include <bits/stdc++.h>
using namespace std;

void f(int n){
  if(n==0) return;
  f(n-1);
  char c = (n+'A'-1);
  cout << c;
  f(n-1);
}

int main(){
  int n;
  cin >> n;
  f(n);
}