#include <bits/stdc++.h>
using namespace std;

int main (){
  int a,b;
  char op;
  cin >> a >> op >> b;
  switch (op)
  {
  case '+':
    cout << a+b << "\n";
    break;
  case '-':
    cout << a-b << "\n";
    break;
  case '*':
    cout << a*b << "\n";
    break;
  case '>':
    (a>b) ? cout << "benar" << "\n" : cout << "salah" << "\n"; 
    break;
  case '<':
    (a<b) ? cout << "benar" << "\n" : cout << "salah" << "\n";
    break;
  case '=':
    (a==b) ? cout << "benar" << "\n" : cout << "salah" << "\n";
    break;
  default:
    break;
  }
  return 0;
}