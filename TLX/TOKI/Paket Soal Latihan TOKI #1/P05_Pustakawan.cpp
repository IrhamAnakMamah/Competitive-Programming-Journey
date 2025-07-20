#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,count = 0;
  cin >> n;
  vector<int> a(n),s(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    s[i] = a[i];
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++)
  {
    if(a[i]!=s[i]){
      for (int j = 0; j < n; j++){
        if(a[j]==s[i]){
          int temp = a[j];
          a[j] = a[i];
          a[i] = temp;
          count++;
        }
      }
      
    }
  }
  cout << count << "\n";
}