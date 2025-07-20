#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a.begin(),a.end());
    for (int i = 0-m, j = 0; i <= m; i++)
    {
      if(a[j]!=i){
        cout << i << endl;
        break;
      }else{
        j++;
      }
    }
    
  }
  
}