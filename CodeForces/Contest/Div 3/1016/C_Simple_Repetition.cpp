#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n,k;
    bool ok = 0;
    cin >> n >> k;

    string s = to_string(n);
    if((s[s.length()-1] - '0') & 1){
      bool cek = 0;
      if(n>=10){
        cek = isPrime(n);
        ok = ((cek && k>1) || (!cek));
      }else{
        int count = n;
        for (int i = 2; i <= k; i++)
        {
          count *= 10;
          count += n;
        }
        if(!isPrime(count)){
          ok = 1;
        }
      }

      cout << (ok ? "NO" : "YES") << endl;
    }else{
      if((n == 2) && k == 1){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
  }
  
}