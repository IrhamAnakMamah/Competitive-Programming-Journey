#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < q; i++)
    {
      string pesan;
      cin >> pesan;
      if(pesan=="pop_back"){
        s.pop_back();
      }else if(pesan=="front"){
        cout << s.front() << endl;
      }else if(pesan=="back"){
        cout << s.back() << endl;
      }else if(pesan=="sort"){
        int l,r;
        cin >> l >> r;
        sort(s.begin()+l-1,s.begin()+r);
      }else if(pesan=="reverse"){
        int l,r;
        cin >> l >> r;
        reverse(s.begin()+l-1,s.begin()+r);
      }else if(pesan=="print"){
        int pos;
        cin >> pos;
        cout << s[pos-1] << endl;
      }else if(pesan=="substr"){
        int l,r;
        cin >> l >> r;
        cout << s.substr(l-1,r) << endl;
      }else if(pesan=="push_back"){
        char x;
        cin >> x;
        s.push_back(x);
      }
    }
       
  }
  
}