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
    int b[n];

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }
    
    int kurang = 0;
    int tambah = 0;

    for (int i = 0; i < n; i++)
    {
      if(a[i] < b[i]){
        tambah += (abs(a[i] - b[i]));
      }else if(a[i] > b[i]){
        kurang += (a[i] - b[i]);
      }
    }
    if(kurang == 0 && tambah == 0){
      cout << 1 << endl;
    }else{
      cout << kurang + 1 << endl;
    }
  }
  
}