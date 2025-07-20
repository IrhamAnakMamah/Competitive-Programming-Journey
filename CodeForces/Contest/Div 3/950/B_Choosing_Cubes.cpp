#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,f,k;
    cin >> n >> f >> k;
    int target = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(i==f-1){
        target = a[i];
      }
    }
    sort(a.rbegin(),a.rend());
    int ans = 0;
    bool ok = 0;
    int indeks = 0;
    for (int i = 0; i < n; i++)
    {
      if(a[i]==target){
        ans++;
        if(ans == 1){
          indeks = i;
        }
      }
    }
    if(indeks+ans>k && indeks+1<=k){
      cout << "MAYBE" << endl;
    }else if(indeks+1 <= k){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}