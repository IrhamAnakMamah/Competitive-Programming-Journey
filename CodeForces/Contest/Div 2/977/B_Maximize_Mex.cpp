#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >>t;
  while (t--)
  {
    int n,x, temp = 0,ans = 0;
    bool ada = 0;
    cin >> n >> x;

    vector<int> same;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
      if(i!=a[i]){
        if(ada && x*(i/x)+temp == i){
          ada = 0;
          temp = 0;
          ans = 0;
        }else if(!ada && ans==0){
          ans = i;
        }
      }else if(a[i] == a[i-1] && i != 0){
        temp = a[i];
        ada = 1;
      }
    }
  }
  
}