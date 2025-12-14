#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> a{0}, b{0};
  
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if(x == 1){
      char c;
      cin >> c;
      a.push_back(a.back() + (c == '(' ? 1 : -1));
      b.push_back(min(a.back(), b.back()));
    }else{
      a.pop_back();
      b.pop_back();
    }
    cout << (a.back() == 0 && b.back() == 0 ? "Yes" : "No") << endl;
  }
  
}