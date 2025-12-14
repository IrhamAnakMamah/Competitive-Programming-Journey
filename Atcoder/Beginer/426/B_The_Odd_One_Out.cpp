#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  vector<int> abjad(27, 0);
  for (int i = 0; i < s.length(); i++)
  {
    abjad[s[i]-'a']++;
  }
  
  for (int i = 0; i < 27; i++)
  {
    if(abjad[i] == 1){
      cout << char(i + 'a') << endl;
      break;
    }
  }
  
}