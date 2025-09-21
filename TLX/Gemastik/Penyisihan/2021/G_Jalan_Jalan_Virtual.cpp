#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int dx[] = {1,1,-1,-1};
int x[MAXN], y[MAXN];

void precomp(){
  x[0] = 0;
  y[0] = 0;
  int j = 1;
  int temp = 1;
  bool ok = 1; //kalo 1 kiri kanan, kalo 0 atas bawah;
  for (int i = 1; i < MAXN; i++)
  {
    if(ok){
      x[i] = x[i-1] + dx[(j-1)%4];
      y[i] = y[i-1];
      temp--;
      if(temp == 0){
        j++;
        temp = j;
        ok^=1;
      }
    }else{
      y[i] = y[i-1] + dx[(j-1)%4];
      x[i] = x[i-1];
      temp--;
      if(temp == 0){
        j++;
        temp = j;
        ok^=1;
      }
    }
  }
  
}

int main(){
  precomp();
  int t;
  cin >> t;
  while (t--)
  {
    int a;
    cin >> a;
    cout << x[a] << " " << y[a] << endl;
  }
  
}