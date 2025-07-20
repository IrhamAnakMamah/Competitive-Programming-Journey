#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    string s;
    int count = 0;
    int cek = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(i!=0){
        count+=(a[i]==a[i-1]);
      }

      if(i==1){
        s+='R';
      }else{
        s+='B';
      }
    }
    
    if(count==n-1){
      cout << "NO\n";
    }else{
      cout << "YES\n";
      cout << s << "\n";
    }
  }
  
}