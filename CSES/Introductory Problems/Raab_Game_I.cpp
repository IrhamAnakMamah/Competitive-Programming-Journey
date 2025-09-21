#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,a,b;
    cin >> n >> a >> b;

    int mx = max(a,b);
    int mn = min(a,b);
    if(a+b > n || mn == 0 && mx > 0){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
      int sama = (n-(a+b));
      if(mx == b){
        int bawah = n;
        int atas = n - sama;
        if(sama == 0){
          atas--;
        }
        int temp = sama;

        for (int i = 0; i < n; i++)
        {
          if(temp){
            cout << i+1 << " ";
            temp--;
          }else{
            if(atas == sama) atas = n;
            cout << atas << " ";
            atas--;
          }
        } 
        cout << endl;
        for (int i = 0; i < n; i++)
        {
          if(sama){
            sama--;
            cout << i+1 << " ";
          }else{
            cout << bawah << " ";
            bawah--;
          }
        }
        cout << endl;
      }else{
        int bawah = n - sama;
        int atas = n;
        int temp = sama;

        for (int i = 0; i < n; i++)
        {
          if(temp){
            cout << i+1 << " ";
            temp--;
          }else{
            cout << atas << " ";
            atas--;
          }
        } 
        cout << endl;
        temp = sama;
        for (int i = 0; i < n; i++)
        {
          if(sama){
            sama--;
            cout << i+1 << " ";
          }else{
            if(bawah == temp){
              bawah = n;
            }
            cout << bawah << " ";
            bawah--;
          }
        }
        cout << endl;
      }
    }
  }
  
}