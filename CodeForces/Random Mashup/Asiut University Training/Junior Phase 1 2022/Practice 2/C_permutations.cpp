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
      if(pesan == "next_permutation"){
        int n;
        cin >> n;
        int k = 0;
        do
        {
          k++;
        } while (next_permutation(s.begin(),s.end()) && k!=n);
        cout << s << endl;
      }else{
        int n;
        cin >> n;
        int k = 0;
        do
        {
          k++;
        } while (prev_permutation(s.begin(),s.end()) && k!=n);
        cout << s << endl;
      }
    }
       
  }
  
}