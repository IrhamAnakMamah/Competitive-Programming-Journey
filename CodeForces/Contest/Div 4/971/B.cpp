#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      for (int j = 0; j < 4; j++)
      {
        if(s[j] == '#'){
          a[i] = j+1;
        }
      }
      
    }

    reverse(a,a+n);

    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
}