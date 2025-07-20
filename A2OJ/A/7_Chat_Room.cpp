#include <iostream>
using namespace std;

int main (){
  string s, temp = "hello";
  int j = 0;
  bool ok = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == temp[j]){
      j++;
    }
  }
  if(j==5){
    cout << "YES" << endl;
  }else cout << "NO" << endl;
}