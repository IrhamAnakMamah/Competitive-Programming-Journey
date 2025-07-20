#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<int> pref(n+1);
  for (int i = 0; i < n; i++)
  {
    if(i){
      pref[i]+=pref[i-1];
    }

    a[i]+=pref[i];
    if(a[i]>0){
      pref[i+1]++;
      if(a[i]<n-i){
        pref[a[i]+i+1]--;
        a[i] = 0;
      }else{
        a[i] -= n-1-i;
      }
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}