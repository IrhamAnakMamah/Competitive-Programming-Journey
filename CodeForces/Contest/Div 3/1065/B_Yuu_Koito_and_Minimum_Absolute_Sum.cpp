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
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    if(a[0] == -1){
      if(a[n-1] == -1){
        a[0] = 0;
      }else{
        a[0] = (a[1] == -1 ? 0 : a[1]);
      }
    }

    int sum = 0;
    for (int i = 1; i < n; i++)
    {
      if(i == n-1 && a[i] == -1) continue;
      if(a[i] == -1){
        a[i] = 0;
      }
      sum += a[i] - a[i-1];
    }
    
    if(a[n-1] == -1){
      a[n-1] = a[n-2] + (sum * -1);
      sum = 0;
    }
    cout << abs(sum) << endl;
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  
}