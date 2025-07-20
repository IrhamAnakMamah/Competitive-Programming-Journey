#include <bits/stdc++.h>
#define ll long long
using namespace std;

string change(string s){
  for (int i = 0; i < 4; i++)
  {
    s[i] = s[i+1];
  }
  return s;
}

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    char c[n][m];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> c[i][j];
      }
    }
    
    int iter = ceil((double)min(n,m)/2);
    int x = n-1;
    int y = m-1;
    int kiri = 0;
    int atas = 0;
    int kanan = m-1;
    int bawah = n-1;

    int ans = 0;
    while(iter--){
      string temp = "";
      int i = x;
      int j = y;
      while(true){
        if(j<kiri){
          break;
        }if(temp.length()==4){
          temp = change(temp);
          temp[3] = c[i][j];
        }else{
          temp += c[i][j];
        }
        if(temp == "1543"){
          ans++;
        }
        j--;
      }
      j++;
      i--;

      while(true){
        if(i<atas){
          break;
        }if(temp.length()==4){
          temp = change(temp);
          temp[3] = c[i][j];
        }else{
          temp += c[i][j];
        }
        if(temp == "1543"){
          ans++;
        }
        i--;
      }
      i++;
      j++;
      while(true){
        if(j>kanan){
          break;
        }if(temp.length()==4){
          temp = change(temp);
          temp[3] = c[i][j];
        }else{
          temp += c[i][j];
        }
        if(temp == "1543"){
          ans++;
        }
        j++;
      }
      j--;
      i++;
      while(true){
        if(i>bawah){
          break;
        }if(temp.length()==4){
          temp = change(temp);
          temp[3] = c[i][j];
        }else{
          temp += c[i][j];
        }
        if(temp == "1543"){
          ans++;
        }
        i++;
      }
      i--;
      j--;

      for (int k = 0; k < 2; k++)
      {
        if(j<kiri){
          break;
        }if(temp.length()==4){
          temp = change(temp);
          temp[3] = c[i][j];
        }else{
          temp += c[i][j];
        }
        if(temp == "1543"){
          ans++;
        }
        j--;
      }
      atas++;
      kanan--;
      kiri++;
      bawah--;
      x--;
      y--;
    }
    cout << ans << "\n";
  }
  
}