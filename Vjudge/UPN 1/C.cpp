#include <bits/stdc++.h>
using namespace std;

int main (){
  int n, a,temp;
  cin >> n;
  vector <int > v;
  cin >> a;
  v.push_back(a);
  for (int i = 0; i < n-1; i++)
  {
    temp = 0;
    cin >> a;
    if(v.back()==a){
      temp = a;
      while(v.back()==temp){
        temp++;
        v.pop_back();
      }
      v.push_back(temp);
    }else{
      v.push_back(a);
    }
  }
  cout << v.size() << "\n";
  return 0;
}