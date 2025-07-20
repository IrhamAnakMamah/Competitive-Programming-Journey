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
    
    for (int i = 0; i < m; i++)
    {
      string s;
      cin >> s;
      if(s=="lower_bound"){
        int k;
        cin >> k;
        int ans = *lower_bound(a.begin(),a.end(),k);
        cout << (ans ? ans : -1) << endl;
      }else if(s=="upper_bound"){
        int k;
        cin >> k;
        int ans = *upper_bound(a.begin(),a.end(),k);
        cout << (ans ? ans : -1) << endl;
      }else{
        int k;
        cin >> k;
        bool ans = binary_search(a.begin(),a.end(),k);
        cout << (ans ? "found" : "not found") << endl;
      }
    }
    
  }
  
}