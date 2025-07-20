#include <iostream>
using namespace std;

int main (){
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    int temp = s[i]-'0';
    if(temp == 9 && i==0) continue;
    if(temp>4){
      string n = to_string(abs(9-temp));
      s[i] = n[0];
    }
  }
  cout << s << "\n";
}