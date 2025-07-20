#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6+5;
ll cache[MAXN];

void calculate(){
  for (int i = 1; i < MAXN; i++)
  {
    for (int j = i; j < MAXN; j+=i)
    {
      cache[j]+=i;
    }
    
  }
  
}

int main(){
  calculate();
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    ll sum = cache[n]-n;
    if(sum>n){
      cout << "abundant" << '\n';
    }else if(sum<n){
      cout << "deficient" << "\n";
    }else{
      cout << "perfect" << "\n";
    }
  }
  
}