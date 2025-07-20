#include <bits/stdc++.h>
using namespace std;

int a[1001];

void checker(int x,int y){
  if((a[x]&1 && a[y]&1) || (a[x]%2==0 && a[y]%2==0)){
    if(a[x] > a[y]){
      cout << abs(a[x] - a[y])/2 << " " << x+1 << " " << y+1 << endl;
    }else{
      cout << abs(a[x] - a[y])/2 << " " << y+1 << " " << x+1 << endl;
    }
  }else{
    cout << "TIDAK SESUAI" << endl;
  }
}

int main(){
  int n;
  cin >> n;

  int temp = 0;
  vector<bool> cek(n+1,0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if(i>=1 && a[i] == a[i-1]){
      cek[i] = 1;
      cek[i-1] = 1;
    }
  }
  
  int x = -1;
  int y = -1;
  int sum = 0;
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    if(cek[i]){
      sum++;
    }else{
      if(x == -1){
        x = i;
      }else if(y == -1){
        y = i;
      }else{
        ok = 0;
      }
    }
  }


  if(sum == n || n == 1){
    cout << "SESUAI" << endl;
  }else if(!ok && n>3){
    cout << "TIDAK SESUAI" << endl;
  }else{
    if(n>3){
      checker(x,y);
    }else if(n==2){
      checker(0,1);
    }else{
      int total = 0;
      for (int i = 0; i < n; i++)
      {
        total += a[i];
      }
      int atas = ceil((total*1.0)/3);
      int bawah = floor((total*1.0)/3);
      if(atas != bawah){
        cout << "TIDAK SESUAI" << endl;
      }else{
        int index1 = -1;
        int index2 = -1;
        bool salah = 0;
        for (int i = 0; i < n; i++)
        {
          if(a[i]!=atas){
            if(index1 == -1){
              index1 = i;
            }else if(index2 == -1){
              index2 = i;
            }else{
              salah = 1;
            }
          }
        }
        if(salah){
          cout << "TIDAK SESUAI" << endl;
        }else{
          checker(index1,index2);
        }
        
      }
    }
  }
  
}