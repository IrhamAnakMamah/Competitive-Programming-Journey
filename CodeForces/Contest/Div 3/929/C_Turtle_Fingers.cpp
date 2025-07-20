#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--){
    int a,b,l;
    cin >> a >> b >> l;
    set<int> st;
    while(true){
      int sum = l;
      while(true){
        st.insert(sum);
        if(sum%b!=0) break;
        sum/=b;
      }
      if(l%a!=0) break;
      l/=a;
    }
    cout << st.size() << "\n";
  }
  
}