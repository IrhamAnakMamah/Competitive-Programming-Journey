#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }

    vector<int> cache;
    for (int i = 0; i < n; i++)
    {
      if(b[i] == 0){
        cache.push_back(a[i]);
      }
    }
    
    sort(cache.begin(), cache.end());
    int idx1 = 0;
    int idx2 = cache.size()-1;
    int pref = 0;

    int k = 0;

    int x[n];
    for (int i = 1; i <= n; i++)
    {
      if(b[i-1] == 0){
        pref += cache[idx1];
        x[i-1] = cache[idx1];
        idx1++;
      }else{
        pref += a[i-1];
        x[i-1] = a[i-1];
      }

      if(pref < 0) k = i+1;
    }

    int y[n];
    pref = 0;
    int kk = 0;

    for (int i = 1; i <= n; i++)
    {
      if(b[i-1] == 0){
        pref += cache[idx2];
        y[i-1] = cache[idx2];
        idx2--;
      }else{
        pref += a[i-1];
        y[i-1] = a[i-1];
      }

      if(pref < 0) kk = i+1;
    }

    if(k < kk){
      for (int i = 0; i < n; i++)
      {
        cout << x[i] << " ";
      }
    }else{
      for (int i = 0; i < n; i++)
      {
        cout << y[i] << " ";
      }
    }
    cout << endl;
  }
  
}