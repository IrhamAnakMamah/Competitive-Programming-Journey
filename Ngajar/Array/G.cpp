#include <iostream>
using namespace std;

int main (){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  bool ok = 1;
  for (int i = 0; i < n/2; i++)
  {
    if(a[i]!=a[n-i-1]){
      ok = 0;
    }
  }
  if(ok){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}