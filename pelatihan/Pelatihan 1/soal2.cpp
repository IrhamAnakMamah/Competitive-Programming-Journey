#include <iostream>
using namespace std;

// 10 20 30 40 100 1000 10000 1000010
// 1101 -> 1110

int main(){
  bool ada = false;
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == '0'){
      ada = true;
    }
  }
  
  if(ada == true){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}