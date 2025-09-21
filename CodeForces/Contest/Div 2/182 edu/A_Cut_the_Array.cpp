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
    int l = 0;
    int r = 0;
    bool ok = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    for (int i = 0; i < n-2; i++)
    {
      sum2 = 0;
      sum1+=a[i];
      for (int j = i+1; j < n-1; j++)
      {
        sum3 = 0;
        sum2+=a[j];
        for (int k = j+1; k < n; k++)
        {
          sum3+=a[k];
        }
        int temp1 = sum1%3;
        int temp2 = sum2%3;
        int temp3 = sum3%3;
        if((temp1 == temp2 && temp2 == temp3) || (temp1 != temp2 && temp2 != temp3 && temp1 != temp3)){
          l = i+1;
          r = j+1;
          ok = 1;
        }
        if(ok) break;
      }
      if(ok) break;
    }
    cout << l << " " << r << endl;
  }
  
}