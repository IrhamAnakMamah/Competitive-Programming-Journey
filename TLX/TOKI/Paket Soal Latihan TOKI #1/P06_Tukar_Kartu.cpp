#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,count = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(a[j]>a[j+1] && j+1<n){
        swap(a[j],a[j+1]);
        count++;
      }
    }
  }
  cout << count << "\n";
}