#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5+5;
int n,q;
ll a[MAXN];

bool search(int b){
  ll left = 0;
  ll right = n-1;
  while(left<=right){
    ll mid = left + ((right-left)/2);
    if(a[mid]==b){
      return true;
    }else if(a[mid]<b){
      left = mid+1;
    }else{
      right = mid-1;
    }
  }
  return false;
}

int main(){
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  while (q--)
  {
    int x;
    cin >> x;
    bool ok = search(x);
    cout << (ok ? "YES" : "NO") << "\n";
  }
  
}