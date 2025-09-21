#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<int> a,l,r;
    int x = 2;
    for (int i = 1; i <= n; i++)
    {
      a.push_back(i);
      l.push_back(1);
      r.push_back(i);

      if(x <= n){
        a.push_back(i);
        l.push_back(x);
        r.push_back(n);
        x++; 
      }
    }
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++)
    {
      cout << a[i] << " " << l[i] << " " << r[i] << endl;
    }
    
  }
  
}