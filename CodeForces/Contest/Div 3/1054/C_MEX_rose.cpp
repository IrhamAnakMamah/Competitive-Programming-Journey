#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;

    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      mp[a]++;
    }
    
    int posisi = 0;
    int temp = 0;
    for(auto [x,y] : mp){
      if(x < k){
        posisi++;
      }else if(x == k){
        temp += y;
        break;
      }
    }
    cout << max(temp, k - posisi) << endl;
  }
  
}