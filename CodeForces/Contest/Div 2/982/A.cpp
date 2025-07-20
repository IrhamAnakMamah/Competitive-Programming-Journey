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
    int a;
    int mx1 = 0;
    int mx2 = 0;
    for(int i = 0; i<n ; i++){
      for (int j = 0; j < 2; j++)
      {
        cin >> a;
        if(j&1){
          mx2 = max(mx2,a);
        }else{
          mx1 = max(mx1,a);
        }
      }
    }

    cout << 2*(mx2+mx1) << "\n";
  }
  
}