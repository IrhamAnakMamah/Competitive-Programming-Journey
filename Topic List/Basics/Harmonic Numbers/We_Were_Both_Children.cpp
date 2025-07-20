#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector <int > a(n+1, 0), b(n+1,0);
    for (int i = 1; i <= n; i++)
    {
      int c;
      cin >> c;
      if(c<=n){
        a[c]++;
      }
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = i; j <= n; j+=i)
      {
        b[j] += a[i]; 
      }
    }
    cout << *max_element(b.begin(), b.end()) << '\n';
  }
  
}