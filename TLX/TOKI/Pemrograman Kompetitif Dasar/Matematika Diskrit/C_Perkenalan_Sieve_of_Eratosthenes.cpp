#include <bits/stdc++.h>
using namespace std;

int main (){
  vector<bool> is_prime(1e6+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= 1e6; i++) {
      if (is_prime[i]) {
          for (int j = i * i; j <= 1e6; j += i){
              is_prime[j] = false;
          }
      }
  }

  vector<int> a;

  for (int i = 0; i <= 1e6; i++)
  {
    if(is_prime[i]){
      a.push_back(i);
    }
  }

  int n;
  cin >> n;
  while (n--)
  {
    int k;
    cin >> k;
    cout << a[k-1] << endl;
  }
  
}