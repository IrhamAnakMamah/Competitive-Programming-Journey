#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  unordered_map<string,string> A;
  unordered_map<string,string> B;

  // Tabel 2 ke tabel 1
  A["CD"] = "AA";
  A["BB"] = "AB";
  A["AC"] = "AC";
  A["CC"] = "AD";

  A["CB"] = "BA";
  A["DB"] = "BB";
  A["AD"] = "BC";
  A["DD"] = "BD";
  
  A["DA"] = "CA";
  A["DC"] = "CB";
  A["BC"] = "CC";
  A["BD"] = "CD";
  
  A["AA"] = "DA";
  A["BA"] = "DB";
  A["CA"] = "DC";
  A["AB"] = "DD";

  // Tabel 1 ke Jawaban
  B["AB"] = "AA";
  B["DC"] = "AB";
  B["CC"] = "AC";
  B["CB"] = "AD";

  B["CA"] = "BA";
  B["DA"] = "BB";
  B["CD"] = "BC";
  B["DD"] = "BD";
  
  B["BC"] = "CA";
  B["AA"] = "CB";
  B["BA"] = "CC";
  B["DB"] = "CD";
  
  B["BD"] = "DA";
  B["AD"] = "DB";
  B["BB"] = "DC";
  B["AC"] = "DD";

  string ans = "";
  for (int i = 0; i < s.length(); i+=2)
  {
    string temp = s.substr(i,2);
    temp = B[A[temp]];
    ans+=temp;
  }
  cout << ans << endl;
}