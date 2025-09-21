#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  int b[n];

  int sum1 = 0;
  int sum2 = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  sort(a,a+n, greater<>());
  sort(b,b+n);
  for (int i = 0; i < n; i++)
  {
    if(a[i] > b[i]){
      sum1 += a[i] - b[i];
    }else{
      sum2 += b[i] - a[i];
    }
  }
  if(sum1 > sum2){
    cout << "Pak Chanek" << endl;
  }else if(sum2 > sum1){
    cout << "Pak Ganesh" << endl;
  }else{
    cout << "Mabar" << endl;
  }
}