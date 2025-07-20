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
    vector<int> x(n);
    vector<int> y(n);
    int maxel = 0;
    int minel = INT_MAX;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      maxel = max(maxel,a[i]);
      minel = min(minel,a[i]); 
      if(i!=0){
        if(maxel == a[i]){
          int temp = a[0];
          a[0] = a[i];
          a[i] = temp;
        }else if(minel == a[i]){
          int temp = a[1];
          a[1] = a[i];
          a[i] = temp;
        }
      }
    }

    int maxim = 0;
    for(int i = 0; i<n ; i++){
      maxim = max(maxim,a[i]);
      x[i] = maxim;
    }

    int minim = INT_MAX;
    for(int i = 0; i<n ; i++){
      minim = min(minim,a[i]);
      y[i] = minim;
    }

    // for(auto z : x){
    //   cout << z << endl;
    // }
    // for(auto z : y){
    //   cout << z << endl;
    // }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += x[i]-y[n-1-i];
    }
    cout << ans << "\n";
  }
  
}