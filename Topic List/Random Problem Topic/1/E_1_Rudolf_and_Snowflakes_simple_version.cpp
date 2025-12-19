#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e6;
int a[MAXN+1];

void precomp(){
  for (int i = 0; i <= MAXN; i++)
  {
    a[i] = 0;
  }
  
  for (int i = 2; i <= 1000; i++)
  {
    int res = 1;
    int temp = i;
    res += temp; 
    int j = 2;
    while (true)
    {
      int temp1 = temp * i;
      if(temp1 + res > MAXN){
        break;
      }
      res += temp1;
      a[res]++;
      temp = temp1;
      j++;
    }
  }
  
}


int main(){
  precomp();
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << (a[n] > 0 ? "YES" : "NO") << endl;
  }
  
}