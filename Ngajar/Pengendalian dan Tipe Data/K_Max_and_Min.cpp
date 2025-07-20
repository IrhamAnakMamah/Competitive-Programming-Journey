#include <iostream>
using namespace std;
// link : https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/K

int main(){
  int a;
  int b;
  int c;
  cin >> a;
  cin >> b;
  cin >> c;
  int mn = min(a,b);
  mn = min(mn,c);

  cout << mn << endl;
}