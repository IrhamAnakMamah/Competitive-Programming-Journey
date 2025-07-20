#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    int sum = 0;
    cin >> n >> k;
    if(n==1){
      cout << k << endl;
      continue;
    }
    for (int i = 30; i >= 0; i--)
    {
      int temp = (1<<i);
      if(temp<k){
        cout << temp-1 << " ";
        k-=temp-1;
        sum = 1;
        break;
      }
    }
    if(k>0){
      cout << k << " ";
      sum++;
    }

    if(sum<n){
      n-=sum;
      while (n--)
      {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }
  
  
}