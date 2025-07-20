#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int a[30];
  memset(a,0,30);
  for (int i = 0; i < 3; i++)
  {
    a[s[i]-'A'] = 1;
  }
  if((a[0] == 1) && (a[1] == 1) && (a[2] == 1)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}