#include <bits/stdc++.h>
using namespace std;

int main(){
  string text, key;
  cin >> text >> key;

  string ans = "";
  for (int i = 0; i < text.length(); i++)
  {
    int temp = text[i] - 'A';
    int temp1 = key[i%(int)key.length()] - 'A';
    cout << (temp^temp1) << endl;
  }
  cout << ans << endl;
}