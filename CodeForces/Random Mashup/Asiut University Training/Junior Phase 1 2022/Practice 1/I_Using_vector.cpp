#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x : a){
      cin >> x;
    }  

    for (int i = 0; i < q; i++)
    {
      string s;
      cin >> s;
      if(s=="pop_back"){
        a.pop_back();
      }else if(s=="front"){
        cout << a.front() << endl;
      }else if(s=="back"){
        cout << a.back() << endl;
      }else if(s=="sort"){
        int l,r;
        cin >> l >> r;
        sort(a.begin()+l-1, a.begin()+r);
      }else if(s=="reverse"){
        int l,r;
        cin >> l >> r;
        reverse(a.begin()+l-1,a.begin()+r);
      }else if(s=="print"){
        int pos;
        cin >> pos;
        cout << a[pos-1] << endl;
      }else if(s=="push_back"){
        int x;
        cin >> x;
        a.push_back(x);
      }
      // cout << "urutan : \n\n";
      // for(auto x : a){
      //   cout << x << " ";
      // }
      // cout << endl << endl;
    }
    
  }
  
}