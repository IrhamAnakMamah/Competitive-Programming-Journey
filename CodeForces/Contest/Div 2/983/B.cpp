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
    int n,k;
    cin >> n >> k;
    if(n==1 && k==1){
      cout << 1 << endl;
      cout << 1 << endl;
    }else if(k==1 || k==n){
      cout << -1 << endl;
    }else{
      int kanan = 0;
      if((k-1)%2==1){
        kanan = 1;
      }else{
        kanan = 2;
      }

      int kiri = 0;
      
      if((n-k)%2==1){
        kiri = 1;
      }else{
        kiri = 2;
      }
      cout << kanan+kiri+1 << endl;
      cout << 1 << " ";
      if(kanan == 2){
        cout << k-1 << " ";
      }
      cout << k << " ";
      cout << k+1 << " ";
      if(kiri == 2){
        cout << n;
      }
      cout << endl;
    }
  }
  
}