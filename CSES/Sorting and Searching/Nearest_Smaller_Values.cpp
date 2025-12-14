#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  stack<pair<int,int>> s;
  s.push({0,0});
  
  for (int i = 0; i < n; i++)
  {
    if(i == 0){
      cout << 0 << " "; 
    }else{
      while (s.top().first != 0 && s.top().first >= a[i])
      {
        s.pop();
      }
      cout << s.top().second << " ";
    }
    s.push({a[i], i + 1});
  }
  cout << endl;
}