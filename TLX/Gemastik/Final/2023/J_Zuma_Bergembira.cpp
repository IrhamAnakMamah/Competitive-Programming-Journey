#include <bits/stdc++.h>
using namespace std;

int main (){
  int m,n;
  cin >> m >> n;
  string a,b;
  cin >> a >> b;

  stack<char> t,d;

  for (int i = 0; i < m; i++)
  {
    t.push(a[i]);
  }
  for (int i = n-1; i >= 0; i--)
  {
    d.push(b[i]);
  }
  
  
  while(!t.empty() && !d.empty()){
    if(t.top() == d.top()){
      while(!t.empty() && t.top() == d.top()){
        t.pop();
      }
    }else{
      t.push(d.top());
    }
    d.pop();
  }

  if(t.empty()){
    cout << "MENANG" << "\n";
  }else{
    cout << "KALAH" << '\n';
  }
}