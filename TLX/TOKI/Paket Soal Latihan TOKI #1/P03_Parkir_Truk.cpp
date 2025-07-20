#include <bits/stdc++.h>
using namespace std;

int main (){
  int a,b,c,x,y,ans=0;
  vector<int > menit(101,0);
  cin >> a >> b >> c;
  for (int i = 0; i < 3; i++)
  {
    cin >> x >> y;
    for (int j = x; j < y; j++)menit[j]++;
  }
  for (int i = 0; i <= menit.size(); i++)
  {
    if(menit[i]==1)ans+=a;
    if(menit[i]==2)ans+=b+b;
    if(menit[i]==3)ans+=c+c+c;
  }
  cout << ans << "\n";
  return 0; 
}