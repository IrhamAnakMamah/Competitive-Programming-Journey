#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> bilangan;

void lucky(ll bil, int jum1, int jum2){
  if(bil>(1LL<<35)){
    return;
  }

  if(jum1 == jum2){
    bilangan.push_back(bil);
  }

  lucky(bil*10 + 4,jum1+1,jum2);
  lucky(bil*10 + 7,jum1,jum2+1);
}

int main(){
  lucky(4,1,0);
  lucky(7,0,1);
  sort(bilangan.begin(),bilangan.end());

  int n;
  cin >> n;

  for (int i = 0; i < bilangan.size(); i++)
  {
    if(bilangan[i]>=n){
      cout << bilangan[i] << "\n";
      return 0;
    }
  }
  
}