  #include <bits/stdc++.h>
  using namespace std;

  int main(){
    int t;
    cin >> t;
    while (t--)
    {
      int n;
      cin >> n;
      int cnt = 0;
      int a[n];
      int b[n];
      for (int i = 0; i < n; i++)
      {
        cin >> a[i];
      }
      bool ok = 1;
      bool notok = 0;
      int x = 0;
      int y = INT_MAX;
      
      for (int i = 0; i < n; i++)
      {
        cin >> b[i];
        if(a[i]<b[i]){
          if(ok!=1) notok = 1;
          ok = 0;
          x = b[i] - a[i];
        }else{
          y = min(y,a[i]-b[i]);
        }
      }
      cout << (notok || y<x ? "NO" : "YES") << endl;
    }
    
  }