#include <iostream>
using namespace std;

int main (){
  int a;
  cin >> a;
  int ans = a;
  for (int i = 0; i < 6; i++)
  {
    cin >> a;
    ans += abs(a);
  }
  
  cout << ans << '\n';
  
}