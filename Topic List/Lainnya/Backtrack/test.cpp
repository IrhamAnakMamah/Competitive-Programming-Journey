#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> subset;
int n =3;

void cari(int k){
  if(k == n){
    ans.push_back(subset);
  }else{
    cari(k+1);
    subset.push_back(k);
    cari(k+1);
    subset.pop_back();
  }
}

int main(){

  string s;
  cin >> s;

  int i = 0;
  do
  {
    cout << s << endl;
    i++;
  } while (next_permutation(s.begin(), s.end()));
  cout << i << endl;
  
}