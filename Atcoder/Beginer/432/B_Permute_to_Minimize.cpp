#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 1; i < s.length() ; i++) {
        if(s[i] != '0') {
            if(s[i] < s[0]) {
                swap(s[i], s[0]);
            }
        }
    }
    
    sort(s.begin() + 1, s.end());
    cout << s << endl;
}