#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = n;
  for (int i = 2; i <= sqrt(n); i++)
  {
    int temp1 = n%i;
    int temp2 = n%(i*i);
    if(temp1==0 && temp2==0){
      ans = min({ans,n/i,n/(i*i)});
    }
  }
  
  cout << ans << "\n";  
}