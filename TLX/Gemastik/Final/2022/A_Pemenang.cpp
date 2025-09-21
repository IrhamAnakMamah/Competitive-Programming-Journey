#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,string> &a, pair<int,string> &b){
  if(a.first == b.first){
    return a.second < b.second;
  }
  return a.first > b.first;
}

int main(){
  int n;
  cin >> n;

  vector<pair<int,string>> tim(n);
  for (int i = 0; i < n; i++)
  {
    string x;
    cin >> x;
    tim[i] = {0,x};
  }
  
  int a,b;
  int i = 0;
  int j = 1;
  while (cin >> a >> b)
  {
    if(a == b){
      tim[i].first++;
      tim[j].first++;
    }else if(a > b){
      tim[i].first+=3;
      tim[j].first--;
    }else{
      tim[j].first+=3;
      tim[i].first--;
    }
    if(j + 1 == n){
      i++;
      j = i+1;
    }else{
      j++;
    }
  }
  sort(tim.begin(), tim.end(), comp);
  cout << tim[0].second << endl;
  
}