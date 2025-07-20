#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      a[i] = (int)s.length();
    }
    int ans = 0;
    int sum = 0;
    int j = 0;
    while (j!=n)
    {
      sum+=a[j];
      if(sum>k){
        break;
      }else{
        ans++;
        j++;
      }
    }
    
    cout << ans << endl;
  } 
  
}