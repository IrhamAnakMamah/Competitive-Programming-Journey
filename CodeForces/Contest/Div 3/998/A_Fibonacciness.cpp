#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int a[4];
    for (int i = 0; i < 4; i++)
    {
      cin >> a[i];
    }
    
    set<int> ans;
    ans.insert(a[0]+a[1]);
    ans.insert(a[3]-a[2]);
    ans.insert(a[2]-a[1]);
    cout << 4-ans.size() << endl;
  }
  
}