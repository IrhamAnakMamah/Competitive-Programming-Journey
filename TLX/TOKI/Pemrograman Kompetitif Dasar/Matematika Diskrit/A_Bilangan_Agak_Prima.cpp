#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,cnt = 0;
    cin >> n;
    for (int i = 2; i*i < n; i++)
    {
      if(n%i==0){
        (i == n/i ? cnt++ : cnt+=2);
      }
    }
    cout << (cnt>2 ? "BUKAN" : "YA") << '\n';
  }
  
}