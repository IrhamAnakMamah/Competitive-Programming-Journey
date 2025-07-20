#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll a,b,c,x = 0, y = 0; //x = jawaban 1, y = jawaban 2
    cin >> a >> b >> c;

    if(a>=c)
    {
      x = -1;
    }else{
      x = 1;
    }
    
    if(a*b > c){
      y = b;
    }else{
      y = -1;
    }

    cout << x << " " << y << "\n";
  }
  
}