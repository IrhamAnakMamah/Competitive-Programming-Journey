#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,l;
    cin >> n >> m >> l;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;

      if(x <= m || x <= l){
        a.push_back(x);
      }
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0;
    int j = (int)a.size() - 1;
    while (i < j)
    {
      int x = a[i];
      int y = a[j];
      if((x <= m && y <= l) || (x <= l && y <= m)){
        ans++;
        i++;
        j--;
      }else{
        j--;
      }
    }
    
    cout << ans << endl;
    
  }
  
}