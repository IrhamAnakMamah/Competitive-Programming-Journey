#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  vector<int> cache1;
  vector<int> cache2;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int temp = 0;
  for (int i = 0; i < (n/2); i++)
  {
    int x = 2*i;
    if(a[x]==a[x+1] && x+1<n){
      cache1.push_back(2);
    }else{
      cache1.push_back(0);
    }
  }

  for (int i = 1; i <= (n/2); i++)
  {
    int x = 2*i;
    if(a[x-1]==a[x]){
      cache2.push_back(2);
    }else{
      cache2.push_back(0);
    }
  }
  
  int mx1 = 0;
  int mx2 = 0;
  temp = 0;
  int index = 0;

  vector <int> b;
  for(auto x : cache1){
    if(x==0){
      mx1 = max(mx1,temp);
      temp = 0;
    }else{
      bool ada = 0;
      int z = a[2*index];
      for (int i = 0; i < b.size(); i++)
      {
        if(z==b[i]){
          ada = 1;
        }
      }
      if(ada){
        mx1 = max(mx1,temp);
        b.clear();
        temp = 2;
        ada = 0;
      }else{
        b.push_back(z);
        temp+=x;
      }
    }
    index++;
  }
  mx1 = max(mx1,temp);
  temp = 0;
  index = 1;
  b.clear();
  for(auto x : cache2){
    if(x==0){
      mx2 = max(mx2,temp);
      temp = 0;
    }else{
      bool ada = 0;
      int z = a[2*index-1];
      for (int i = 0; i < b.size(); i++)
      {
        if(z==b[i]){
          ada = 1;
        }
      }
      if(ada){
        mx2 = max(mx2,temp);
        b.clear();
        temp = 2;
        ada = 0;
      }else{
        b.push_back(z);
        temp+=x;
      }
    }
  }
  mx2 = max(mx2,temp);
  cout << max(mx1,mx2) << endl;
}