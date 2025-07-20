#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int nol = 0;
    int satu = 0;
    for (int i = 0; i < n*2; i++)
    {
      int a;
      cin >> a;
      if(a==1)satu++;
      else nol++; 
    }
    if(satu&1){
      cout << 1 << " ";
    }else{
      cout << 0 << " ";
    }

    if(satu==0){
      cout << 0 << endl;
    }else{
      cout << min(satu,nol) << endl;
    }
  }
  
}