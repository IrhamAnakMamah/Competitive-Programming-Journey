//print semua kemungkinan

#include <bits/stdc++.h>
using namespace std;

vector<int> ds;

void f(int a[],int n ,int t,int sum){
  if(n<0){
    if(sum==t){
      reverse(ds.begin(),ds.end());
      for(auto it : ds) cout << it << " ";
      cout << '\n';
    }
    return;
  }
  //pick, jika element dalam array mau diambil
  ds.push_back(a[n]);
  sum+=a[n];

  f(a,n-1,t,sum);

  //not pick, jika element dalam array tidak mau diambil
  sum-=a[n];
  ds.pop_back();
  f(a,n-1,t,sum);
}

int main (){
  int n,t;//t = target
  cin >> n >> t;
  int a[n];
  for(int i = 0;i<n;i++){
    cin >> a[i];
  }
  f(a,n-1,t,0);
  return 0;
}