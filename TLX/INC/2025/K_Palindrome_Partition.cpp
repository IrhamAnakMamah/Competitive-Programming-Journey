#include <bits/stdc++.h>
using namespace std;

string solve(string jawaban, string temp, string ganjil){
      int l = 0;
      int r = (int)jawaban.size()-1;
      int idx = 0;
      while (idx < (int)temp.size())
      {
        jawaban[l] = temp[idx];
        jawaban[r] = temp[idx+1];
        idx+=2;
        l++;
        r--;
      }
      idx = 0;
      while (idx < (int)ganjil.size())
      {
        if(idx + 1 == (int)ganjil.size()){
          jawaban[l] = ganjil[idx];
          idx++;
          l++;
        }else{
          jawaban[l] = ganjil[idx];
          jawaban[r] = ganjil[idx+1];
          idx+=2;
          l++;
          r--;
        }
      }
      return jawaban;
}

int main(){
  string s;
  cin >> s;

  vector<int> freq(27, 0);
  for (int i = 0; i < (int)s.length(); i++)
  {
    freq[s[i] - 'a']++;
  }
  
  vector<string> ans;

  string temp = "";
  string ganjil = "";
  int i = 0;
  int ok = 0;
  for (i; i < 27; i++)
  {
    if(freq[i]%2 == 0){
      for (int j = 0; j < freq[i]; j++)
      {
        temp+='a' + i;
      }
    }else{
      if(ok){
        string jawaban = temp + ganjil;
        ans.push_back(solve(jawaban, temp, ganjil));
        temp = "";
        ganjil = "";
        for (int j = 0; j < freq[i]; j++)
        {
          ganjil += 'a' + i;
        }
        break;
      }else{
        ok = 1;
        for (int j = 0; j < freq[i]; j++)
        {
          ganjil += 'a' + i;
        }
      }
    }
  }

  i++;
  
  for (i; i < 27; i++)
  {
    if(freq[i]%2==0 && freq[i] != 0){
      for (int j = 0; j < freq[i]; j++)
      {
        temp+='a' + i;
      }
    }else if(freq[i]&1){
      string jawaban = temp + ganjil;
      
      ans.push_back(solve(jawaban, temp, ganjil));
      temp = "";
      ganjil = "";
      for (int j = 0; j < freq[i]; j++)
      {
        ganjil+='a'+i;
      }
      
    }
  }

  if(temp != "" || ganjil != ""){
    string jawaban = temp + ganjil;
    ans.push_back(solve(jawaban, temp, ganjil));
  }
  
  cout << ans.size() << endl;
  for(auto x : ans){
    cout << x << endl;
  }
  
}