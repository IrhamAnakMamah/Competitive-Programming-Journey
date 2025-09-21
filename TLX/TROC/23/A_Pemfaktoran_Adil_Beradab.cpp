#include <bits/stdc++.h>
using namespace std;

int a[101];

void precomp(){
  for (int i = 1; i <= 100; i++)
  {
    for (int j = i; j <= 100; j+=i)
    {
      a[j]++;
    }
  }
}

int main(){
  precomp();
  vector<vector<int>> b(10000, vector<int>(10000, 0));
  int n;
  cin >> n;
  
  if(a[n] == 5){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}