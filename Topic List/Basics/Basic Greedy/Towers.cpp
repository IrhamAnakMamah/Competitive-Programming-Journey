#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    int l = 0;
    int r = ans.size();
    while(l<r){
      int mid = (l+r)/2;
      if(ans[mid]>k)r = mid;
      else l = mid+1;
    }
    if(l == (int)ans.size())ans.push_back(k);
    else ans[l] = k;
  }
  cout << ans.size() << endl;
}