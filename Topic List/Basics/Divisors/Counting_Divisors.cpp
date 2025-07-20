#include <bits/stdc++.h>
#define ll long long
using namespace std;

int z[1000001];

int main(){
  memset(z,-1,1000001);
  ll t;
  cin >> t;
  while (t--)
  {
    int n,cnt = 0;
    cin >> n;
    if(z[n]!=-1){
      cout << z[n] << "\n";
      continue;
    }
 
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;
            if (i != sqrt(n)){
                cnt++;
            }
        }
    }
    z[n] = cnt;
    cout << z[n] << "\n";
  }
  
}