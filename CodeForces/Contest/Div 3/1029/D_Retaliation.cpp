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
    
    // kasus pertama ngecek semua nya dulu sama atau ngga
    bool sama = 1;
    for (int i = 1; i < n; i++)
    {
      if(a[i]!=a[i-1]){
        sama = 0;
      }
    }
    if(sama){
      int temp1 = a[0];
      int temp2 = a[0];
      
      while (temp1 > 0 && temp2 > 0)
      {
        if(temp1 > temp2){
          temp1-=n;
          temp2--;
        }else{
          temp1--;
          temp2-=n;
        }
      }

      if(temp1 == 0 && temp2 == 0){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }else{
      int x = a[0];
      int y = a[n-1];
      int step1 = 0;
      int step2 = 0;
      int step3 = 0;
      bool ok = 1;

      while (x > 0 && y > 0)
      {
        if(x < y){
          step1++;
          x--;
          y-=n;
        }else if(x > y){
          step2++;
          x-=n;
          y--;
        }else{
          step1++;
          x--;
          y-=n;
        }
      }
      if(x == 0 && y == 0){
        for (int i = 1; i < n-1; i++)
        {
          a[i] -= ((i+1)*step1);
          a[i] -= ((n-i)*step2);
          if(a[i] != 0){
            ok = 0;
            break;
          }
        }
        cout << (ok ? "YES" : "NO") << endl;
      }else{
        cout << "NO" << endl;
      }
    }
  }
  
}