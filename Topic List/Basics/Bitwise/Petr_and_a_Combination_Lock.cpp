#include <bits/stdc++.h>
using namespace std;

int n;
int a[16];

bool f(int jumlah,int i){
  if(n == i){
    if(jumlah==0){
      return true;
    }else{
      return false;
    }
  }

  if(f((jumlah+a[i])%360,i+1)==true){
    return true;
  }
  if(f((jumlah-a[i])%360,i+1)==true){
    return true;
  }

  return false;
}

int main(){
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  bool ya = f(0,0);
  if(ya){
    cout << "YES" << "\n";
  }else{
    cout << "NO" << "\n";
  }
}