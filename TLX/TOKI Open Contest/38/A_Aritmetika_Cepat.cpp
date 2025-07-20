#include <iostream>
using namespace std;

int main (){
  int a[7], ans = 0;
  for (int i = 0; i < 7; i++)
  {
    cin >> a[i];
  }

  if(a[0] - a[1] > a[0] + a[1]){
    ans = a[0] - a[1];
  }else{
    ans = a[0] + a[1];
  }

  for (int i = 2; i < 7; i++)
  {
    if(ans - a[i] > ans + a[i]){
      ans = ans - a[i];
    }else{
      ans = ans + a[i];
    }
  }
  cout << ans << '\n';
  
}