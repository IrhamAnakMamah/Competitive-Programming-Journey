#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,k;
    cin >> n >> m >> k;
    int a[m];
    vector<bool> cek (n+1,0);
    for (int i = 0; i < m; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
      int x;
      cin >> x;

      cek[x] = 1;
    }
    
    for (int i = 0; i < m; i++)
    {
      int temp = k - (cek[a[i]]==1);
      if(temp<n-1){
        cout << 0;
      }else{
        cout << 1;
      }
    }
    cout << endl;
  }
  
}