//print hanya satu kemungkinan menggunakan bool

#include <bits/stdc++.h>
using namespace std;

vector<int> ds;

bool f(int n,int k,int a[],int sum){
  if(n<0){
    if(sum==k){
      reverse(ds.begin(), ds.end());
      for(auto it : ds) cout << it << " ";
      cout << "\n";
      return true;
    }else return false;
  }

  ds.push_back(a[n]);
  sum+=a[n];
  if(f(n-1,k,a,sum)==true){
    return true;
  }
  ds.pop_back();
  sum-=a[n];
  if(f(n-1,k,a,sum)==true){
    return true;
  }

  return false;
}

int main (){
  int n,k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  f(n-1,k,a,0);
}