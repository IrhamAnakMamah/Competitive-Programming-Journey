#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    if(s[2] == '2'){
      sum += 3;
    }else if(s[2] == '3'){
      sum += 2;
    }else{
      sum++;
    }
  }
  
  cout << ceil((sum * 1.0)/6) << endl;
}