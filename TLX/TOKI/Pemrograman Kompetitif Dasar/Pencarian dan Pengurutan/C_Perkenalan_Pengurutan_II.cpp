#include <bits/stdc++.h>
using namespace std;

vector<pair<string,int>> ans;

void bubbleSort(int size) {
  for (int step = 0; step < size -1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (ans[i].second >= ans[i + 1].second){
        if(ans[i].second == ans[i + 1].second && ans[i].first < ans[i + 1].first){
          continue;
        }
        auto temp = ans[i];
        ans[i] = ans[i + 1];
        ans[i + 1] = temp;
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  string s;
  for(int i = 0; i<n ; i++){
    cin >> s;
    ans.push_back({s,(int)s.length()});
  } 

  bubbleSort(n);

  for(int i = 0;i<ans.size();i++){
    cout << ans[i].first << endl;
  }

}