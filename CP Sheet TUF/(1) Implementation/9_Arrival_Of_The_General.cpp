#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,a,last = 0, first = 0, maxim = INT_MIN, minim = INT_MAX;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a;
    if(a<=minim){
      if(a==minim){
        last = i;
      }else{
        last = i;
        minim = a;
      }
    }else if(a>maxim){
      first = i;
      maxim = a;
    }
  }
  cout << n-last+first-1 << '\n';
}