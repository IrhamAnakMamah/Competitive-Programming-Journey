#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;

  while (t--)
  {
    int n,a;
    cin >> n >> a;

    int p[n];
    for (int i = 0; i < n; i++)
    {
      cin >> p[i];
    }
    
    int kiri = 0;
    int kanan = 0;
    int tengah = 0;

    for (int i = 0; i < n; i++)
    {
      if(a-p[i] == 0){
        tengah++;
      }else if(a - p[i] > 0){
        kiri++;
      }else{
        kanan++;
      }
    }
    if(kanan < kiri){
      cout << a-1 << endl;
    }else   {
      cout << a+1 << endl;
    }
  }
  
}