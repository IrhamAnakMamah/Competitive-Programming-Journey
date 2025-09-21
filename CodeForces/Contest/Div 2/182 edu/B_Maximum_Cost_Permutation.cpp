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
    int nol = 0;
    int awal = -1;
    int akhir = -1;
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(a[i] != i+1){
        if(awal == -1){
          awal = i+1;
          akhir = i+1;
        }else{
          akhir = i+1;
        }
      }
      if(a[i] == 0){
        nol++;
        idx = i+1;
      }
    }
    
    auto print = [&] (){
      cout << (awal == akhir || awal == -1 ? 0 : (akhir - awal) + 1) << endl;
    };

    if(nol == 1){
      if(awal == idx || akhir == idx){
        bool ok = 0;
        for (int i = 0; i < n; i++)
        {
          if(idx-1 == i){
            continue;
          }else if(idx == a[i]){
            ok = 1;
          }
        }
        
        if(ok){
          print();
        }else{
          awal = -1;
          akhir = -1;
          for (int i = 0; i < n; i++)
          {
            if(idx-1 == i){
              continue;
            }
            if(a[i] != i+1){
              if(awal == -1){
                awal = i+1;
                akhir = i+1;
              }else{
                akhir = i+1;
              }
            }
          }
          print();
        }
      }else{
        print();
      }
    }else{
      print();
    }
  }
  
}