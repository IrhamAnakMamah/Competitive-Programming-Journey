#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 1e6+5;
 
vector<int> dp(mxN,INT_MAX);
int j = 0;
int n,x;
 
int a[mxN];
 
int f(int i,int jumlah, int coin){
  if(jumlah>=x){
    if(jumlah==x){
      return coin;
    }else{
      return INT_MAX;
    }
  }

  if(dp[i]!=INT_MAX){
    return dp[i];
  }
 
  int sum = INT_MAX;
  for (int j = i; j < n; j++)
  {
    int temp = f(j,jumlah+a[j],coin+1);
    sum = min(temp,sum);
  }
  return dp[i] = min(dp[i],sum);
} 
 
int main(){
  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int sum = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    int temp = 0;
    temp = f(i,a[i],1);
    sum = min(sum,temp);
  }
  cout << (sum == INT_MAX ? -1 : sum) << endl;
}