#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << endl;
        return;
    }
    bool is_palindrome = true;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        string temp = s;
        for (char &c : temp) c = (c == '0' ? '1' : '0'); 
        if (temp == t) {
            cout << "1\n1 " << n << endl;
            return;
        }
    }
    vector<pair<int, int>> ans;
    string cur = s;

    auto do_flip = [&](int l, int r) {
        ans.push_back({l + 1, r + 1}); 
        for (int i = l; i <= r; i++) {
            cur[i] = (cur[i] == '0' ? '1' : '0');
        }
    };

    for (int i = 0; i < n - 2; i++) {
        if (cur[i] == t[i]) continue;
        if (cur[i+2] == cur[i]) {
            do_flip(i, i + 2);
        } 
        else if (cur[i+1] == cur[i]) {
            do_flip(i, i + 1);
        } 
        else {
            do_flip(i + 1, i + 2);
            do_flip(i, i + 2);
        }
    }

    if (cur[n - 2] != t[n - 2]) {
        if (cur[n - 2] == cur[n - 1]) {
            do_flip(n - 2, n - 1);
        }
    }

    if (cur == t) {
        cout << ans.size() << endl;
        for (auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}