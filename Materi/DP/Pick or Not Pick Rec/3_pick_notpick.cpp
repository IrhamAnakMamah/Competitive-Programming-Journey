//menghitung banyaknya kemungkinan

#include <bits/stdc++.h>
using namespace std;

int f(int n,int t,int a[], int sum){
  if(n<0){
    if(sum==t){
      return 1;
    }
    else return 0;
  }

  sum+=a[n];
  int left = f(n-1,t,a,sum);
  
  sum-=a[n];
  int right = f(n-1,t,a,sum);

  return left + right;
}

int main (){
  int n,t;
  cin >> n >> t;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  cout << f(n-1,t,a,0) << "\n";
}