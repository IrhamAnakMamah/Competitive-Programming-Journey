#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,temp1 = 0, temp2 = 0, cnt1 = 0, cnt2 = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    for (int i = 0; i < n; i+=2)
    {
      temp1 = max(temp1,a[i]);
      cnt1++;
    }

    for (int i = 1; i < n; i+=2)
    {
      if(i>=n)break;
      temp2 = max(temp2,a[i]);
      cnt2++;
    }
    
    cout << max(temp2 + cnt2, temp1 + cnt1) << "\n";    
  }
  
}