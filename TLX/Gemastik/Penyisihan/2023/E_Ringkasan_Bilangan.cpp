#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  set<int> a;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.insert(x);
  }
  
  vector<int> b;
  for(auto x : a){
    b.push_back(x);
  }

  sort(b.begin(), b.end());

  int awal = b[0];
  int akhir = 0;
  bool status = 0;
  
  for (int i = 0; i < b.size()-1; i++)
  {
    if(b[i]==b[i+1]-1){
      status = 1;
      akhir = b[i+1];
    }else if(status){
      cout << awal << "-" << akhir << ",";
      awal = b[i+1];
      status = 0;
    }else{
      if(i+1 < b.size()){
        cout << b[i] << ",";
        awal = b[i+1];
      }
    }
  }
  if(status){
    cout << awal << "-" << akhir << endl;
  }else{
    cout << awal << endl;
  }
}