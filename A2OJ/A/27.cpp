#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,d,ans = 0, temp = 0;
  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    temp+=a;
  }

  if((n-1)*10+temp <= d){
    cout << (d-temp)/5 << '\n';
  }else{
    cout << -1 << endl;
  }
}