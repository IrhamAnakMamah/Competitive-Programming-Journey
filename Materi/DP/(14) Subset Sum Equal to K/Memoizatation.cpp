#include <bits/stdc++.h>
using namespace std;

bool f(int a[],int n,int k){
  if(n<0){
    if(k==0){
      return true;
    }else return false;
  }

  if(f(a,n-1,k)){
    return true;
  }

  if(f(a,n-1,k-a[n])){
    return true;
  }

  return false;
}

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    bool ok = f(a,n-1,k);
    (ok) ? cout << "true" << "\n" : cout << "no" << "\n";
  }
  
}
