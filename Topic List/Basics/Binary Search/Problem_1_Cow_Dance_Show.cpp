#include <bits/stdc++.h>
using namespace std;

int n,t;

vector<int> a;

bool cek(int k) {
  int time = 0;
  priority_queue<int> stage;
  for (int i = 0; i < n; i++) {
    if (stage.size() == k) {
      time = -stage.top();
      stage.pop();
    }
    if (time + a[i] > t) {
      return false;
    } else {
      stage.push(-time - a[i]);
    }
  }
  return true;
}

int main()
{
  
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);

  cin >> n >> t;
    
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }
  
  int l = 1;
  int r = n;
  while (l < r)
  {
    int mid = (l+r)/2;
    if(cek(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  cout << l << endl;
}