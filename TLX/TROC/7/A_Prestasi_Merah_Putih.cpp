#include <iostream>
using namespace std;

int main(){
  int n; // banyaknya negara
  int ans = 0;
  cin >> n;

  int a[n+1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  
  int x;
  cin >> x;

  for (int i = 1; i <= n; i++)
  {
    if(a[i]==x){
      ans = i;
    }
  }
  
  cout << ans << endl;
}