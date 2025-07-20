#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,m;
  cin >> n >> m;
  set<int> a;
  for (int i = 1; i <= n; i++)
  {
    int x,y;
    cin >> x;
    for (int j = 0; j < x; j++)
    {
      cin >> y;
      if(m>y){
        a.insert(i);
      }
    }
  }
  cout << a.size() << "\n";
  for(auto b : a){
    cout << b << " ";
  }
  cout << '\n';
}