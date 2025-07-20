  #include <bits/stdc++.h>
  using namespace std;

  int main(){
    int t;
    cin >> t;
    while (t--)
    {
      int n,j,k;
      cin >> n >> j >> k;
      
      int a[n];
      int player = 0;
      for (int i = 0; i < n; i++)
      {
        cin >> a[i];
        if(i==j-1){
          player = a[i];
        }
      }
      
      sort(a,a+n, greater<>());
      if(player != a[0] && k==1){
        cout << "NO" << endl;
      }else{
        cout << "YES" << endl;
      }
    }
    
  }