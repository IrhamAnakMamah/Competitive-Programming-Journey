#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int atas = 0;
    int bawah = 0;

    for (int i = 0; i < s.length(); i++)
    {
      if(s[0]=='-'){
        atas++;
      }else{
        bawah++;
      }
    }
    
    if(atas<2 || bawah == 0){
      cout << 0 << endl;
    }else{
      int ans = 0;
      
    }
  }
  
}