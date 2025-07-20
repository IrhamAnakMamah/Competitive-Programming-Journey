#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,a,b,minim = 0, temp = 0, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    sum = sum-a+b;
    if(i==n-1) break;
    if(sum>minim){
      minim = sum;
    }
  }
  cout << minim << "\n";
}