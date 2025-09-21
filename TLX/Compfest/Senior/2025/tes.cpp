#include <iostream>
#include <vector> 
using namespace std;

int main(){
  int n,m,k;
  n = 4;
  m = 5;
  k = 2;

  vector<int> maju(n+1, 0);
  vector<int> mundur(n+1, 0);
  maju[1] = 1;
  for (int xx = 0; xx < k; xx++)
  {
    vector<int> cache1(n+2, 0);
    vector<int> cache2(n+2, 0);
    bool ok = 1;
    for (int i = 0; i <= n; i++)
    {
      ok = 1;
      if(maju[i] > 0){
        int temp = maju[i];
        int count = m;
        int j = i+1;
        while(count--){
          if(ok){
            if(j > n){
              ok = 0;
              j-=2;
              cache2[j] += temp;
              j--;
            }else{
              cache1[j] += temp;
              j++;
            }
          }else{
            if(j == 0){
              ok = 1;
              j++;
              cache1[j] += temp;
              j++;
            }else{
              cache2[j] += temp;
              j--;
            }
          }
        }
      }
      if(mundur[i] > 0){
        ok = 0;
        int temp = mundur[i];
        int count = m;
        int j = i-1;
        while(count--){
          if(ok){
            if(j > n){
              ok = 0;
              j-=2;
              cache2[j] += temp;
              j--;
            }else{
              cache1[j] += temp;
              j++;
            }
          }else{
            if(j == 0){
              ok = 1;
              j+=2;
              cache1[j] += temp;
              j++;
            }else{
              cache2[j] += temp;
              j--;
            }
          }
        }
      }
    }
    
    for(auto x : cache1){
      cout << x << " ";
    }
    cout << endl;
    for(auto x : cache2){
      cout << x << " ";
    }
    cout << endl;
    maju = cache1;
    mundur = cache2;
  }
  
}