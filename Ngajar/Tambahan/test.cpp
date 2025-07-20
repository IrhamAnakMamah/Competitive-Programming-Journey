#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int pref[n+1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  while(true){
    int l,r;
    cin >> l >> r;
    if(l==-1 || r==-1) break;
    cout << pref[r+1] - pref[l] << endl << endl;
  }
}