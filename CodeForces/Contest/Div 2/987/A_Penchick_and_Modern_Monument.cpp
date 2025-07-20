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
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
      int temp = 0;
      for (int j = i+1; j < n; j++)
      {
        if(a[i]==a[j]){
          temp++;
        }
      }
      mx = max(mx,temp);
    }
    cout << n-mx-1 << endl;
  }
  
}