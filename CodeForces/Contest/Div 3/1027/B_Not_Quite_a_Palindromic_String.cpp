#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    int a[2];
    a[0] = 0;
    a[1] = 0;
    // a[0] = 0, a[1] = 1

    for (int i = 0; i < s.length(); i++)
    {
      a[s[i]-'0']++;
    }

    int ans = 0;
    while(k>0 && (a[0] >= 2 || a[1] >= 2)){
      if(a[1] > a[0]){
        a[1]-=2;
        ans++;
        k--;
      }else{
        a[0]-=2;
        ans++;
        k--;
      }
    }

    if(k == 0 && abs(a[1]-a[0])<2){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}