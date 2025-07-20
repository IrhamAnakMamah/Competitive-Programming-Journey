#include <bits/stdc++.h>
using namespace std;

int main(){
  string n;
  cin >> n;
  int a = 0,b = 0,c = 0;
  for(int i = 0;i<n.length();i++){
    if(n[i]=='1')a++;
    if(n[i]=='2')b++;
    if(n[i]=='3')c++;
  }

  if(a==1 && b==2 && c==3){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}