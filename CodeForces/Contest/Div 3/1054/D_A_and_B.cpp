#include <bits/stdc++.h>
using namespace std;

long long minMoves(const string &s, char target) {
    vector<int> pos;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == target) pos.push_back(i);
    }
    if (pos.empty()) return LLONG_MAX;
    
    int k = pos.size();
    int mid = k / 2;
    long long base = pos[mid] - mid;
    
    long long cost = 0;
    for (int i = 0; i < k; i++) {
        cost += llabs(pos[i] - (base + i));
    }
    return cost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        long long resA = minMoves(s, 'a');
        long long resB = minMoves(s, 'b');
        cout << min(resA, resB) << "\n";
    }
    return 0;
}
