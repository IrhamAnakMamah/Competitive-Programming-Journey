#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    int a[n];
    int genap = 0;
    int ganjil = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(a[i]&1){
        ganjil++;
      }else{
        genap++;
      }
    }
    
    if(min(ganjil, genap) != 0){
      sort(a, a+n);
    }
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
    
  }
}