#include <stdio.h>

int max(int a, int b){
  if(a>b){
    return a;
  }else{
    return b;
  }
}

int main(){
  int n,k,ans[3] = {0,0,0};
  scanf("%d%d",&n,&k);
  for (int i = 1; i <= k; i++)
  {
    for (int j = i+1; j <= n; j++)
    {
      int x = i&j;
      int y = i|j;
      int z = i^j;
      if(x < k){
        ans[0] = max(ans[0],x);
      }
      if(y < k){
        ans[1] = max(ans[1],y);
      }
      if(z < k){
        ans[2] = max(ans[2],z);
        
      }
    }
  }
  for (int i = 0; i < 3; i++)
  {
    printf("%d\n",ans[i]);
  }
  
}