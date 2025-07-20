#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int j = 0;
  int temp = 0;
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    temp++;
    if(a[i]>b[j]){
      temp--;
      j++;
    }
    mx = max(mx,temp);
  }
  
  cout << mx << endl;
}