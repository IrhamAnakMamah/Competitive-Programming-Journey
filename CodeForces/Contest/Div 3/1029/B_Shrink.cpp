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
    if(n&1){
      int k  = 1;
      for (int i = 0; i <= (n/2); i++)
      {
        if(i == (n/2)){
          a[i] = k;
        }else{
          a[i] = k;
          k++;
          a[n-i-1] = k;
          k++;
        }
      }
    }else{
      int k = 1;
      for (int i = 0; i < (n/2); i++)
      {
        a[i] = k;
        k++;
        a[n-i-1] = k;
        k++;
      }
    }
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
    
  }
  
}