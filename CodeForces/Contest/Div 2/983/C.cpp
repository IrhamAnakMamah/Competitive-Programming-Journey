#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int > a(n);
    for(auto &x : a){
      cin >> x;
    }
    sort(a.begin(),a.end());

    int j = n-1;
    int ans = INT_MAX;
    for(int i = n-1;i>=0;i--){
      for(j = min(i,j);j>0 && a[j-1]+a[j]>a[i];j--);
      ans = min(ans,n-(i-j+1));
    }
    cout << ans << "\n";
  }
  
}